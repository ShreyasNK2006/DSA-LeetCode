"""
leetcode_to_github.py
=====================
Fetches your accepted LeetCode submissions (oldest → newest) and saves
2 new problems per run to the problems/ directory.

Required GitHub Secrets (Settings → Secrets and variables → Actions):
  LEETCODE_SESSION   – value of the LEETCODE_SESSION cookie from your browser
  LEETCODE_USERNAME  – your LeetCode username
  GEMINI_API_KEY     – (optional) Google Gemini API key for AI explanations

Optional GitHub Secrets / environment variables:
  REPO_NAME          – owner/repo (e.g. ShreyasNK2006/DSA-LeetCode)
  COMMIT_NAME        – display name for git commits
  COMMIT_EMAIL       – email for git commits
"""

import requests
import os
import json
import datetime
import time
import subprocess

# ---------------------------------------------------------------------------
# Optional AI dependency
# ---------------------------------------------------------------------------
try:
    import google.generativeai as genai
    HAS_GENAI = True
except ImportError:
    HAS_GENAI = False

# ---------------------------------------------------------------------------
# Configuration – all sourced from environment / GitHub Secrets
# ---------------------------------------------------------------------------
# LeetCode authentication cookie.
# ▸ Placeholder: set the LEETCODE_SESSION secret in your repo's
#   Settings → Secrets and variables → Actions.
LEETCODE_SESSION = os.getenv("LEETCODE_SESSION")

# Your LeetCode username.
LEETCODE_USERNAME = os.getenv("LEETCODE_USERNAME")

# Google Gemini API key for AI-generated code explanations.
# ▸ Placeholder: set the GEMINI_API_KEY secret in your repo.
#   Leave it unset to disable AI explanations (a placeholder comment
#   will be inserted instead).
GEMINI_API_KEY = os.getenv("GEMINI_API_KEY")

# GitHub repo (used for optional GitHub API calls, not strictly required).
REPO_NAME = os.getenv("REPO_NAME")
GITHUB_TOKEN = os.getenv("GITHUB_TOKEN")

# ---------------------------------------------------------------------------
# Initialise Gemini if available
# ---------------------------------------------------------------------------
if HAS_GENAI and GEMINI_API_KEY:
    genai.configure(api_key=GEMINI_API_KEY)

# ---------------------------------------------------------------------------
# LeetCode HTTP headers (cookie-based auth)
# ---------------------------------------------------------------------------
HEADERS = {
    "cookie": f"LEETCODE_SESSION={LEETCODE_SESSION}",
    "User-Agent": "Mozilla/5.0",
    "Referer": "https://leetcode.com",
    "Content-Type": "application/json",
}

# ---------------------------------------------------------------------------
# Language → file extension mapping
# ---------------------------------------------------------------------------
EXT_MAP = {
    "python3": "py",
    "python":  "py",
    "cpp":     "cpp",
    "java":    "java",
    "c":       "c",
    "javascript": "js",
    "typescript": "ts",
    "csharp":  "cs",
    "kotlin":  "kt",
    "swift":   "swift",
    "golang":  "go",
    "rust":    "rs",
    "scala":   "scala",
    "dart":    "dart",
}

# ===========================================================================
# LeetCode API helpers
# ===========================================================================

def get_all_submissions(limit: int = 200) -> list:
    """
    Fetch accepted submissions (with code) from LeetCode.
    Returns the list sorted oldest → newest.
    """
    url = "https://leetcode.com/api/submissions/"
    submissions = []
    offset = 0

    while len(submissions) < limit:
        res = requests.get(
            f"{url}?offset={offset}&limit=20",
            headers=HEADERS,
            timeout=15,
        )
        if res.status_code != 200:
            print(f"❌ Failed to fetch submissions (HTTP {res.status_code}): {res.text[:200]}")
            break

        data = res.json()
        for sub in data.get("submissions_dump", []):
            if sub.get("status_display") == "Accepted" and sub.get("code"):
                submissions.append(sub)

        if not data.get("has_next"):
            break

        offset += 20
        time.sleep(0.5)

    # Reverse so oldest submission comes first
    submissions.reverse()
    return submissions


def get_problem_number(slug: str) -> str:
    """
    Query the LeetCode GraphQL API to get the frontend problem number for a
    given title slug (e.g. 'two-sum' → '0001').

    Uses the LEETCODE_SESSION cookie for authentication so that even premium
    / contest problems can be looked up.
    Returns a zero-padded 4-digit string so that files sort numerically.
    """
    url = "https://leetcode.com/graphql"
    query = """
    query getQuestionDetail($titleSlug: String!) {
      question(titleSlug: $titleSlug) {
        questionFrontendId
        title
      }
    }
    """
    payload = {"query": query, "variables": {"titleSlug": slug}}

    try:
        res = requests.post(url, json=payload, headers=HEADERS, timeout=10)
        data = res.json()
        frontend_id = data["data"]["question"]["questionFrontendId"]
        # Zero-pad to 4 digits so filesystem sorting matches problem order
        return str(frontend_id).zfill(4)
    except Exception as exc:
        print(f"⚠️  Could not fetch problem number for '{slug}': {exc}")
        return "0000"

# ===========================================================================
# AI explanation helper
# ===========================================================================

def get_ai_explanation(code: str, lang_ext: str) -> str:
    """
    Generate a human-readable explanation of the solution using the Gemini API.

    If GEMINI_API_KEY is not set, returns a placeholder string so you can
    fill it in later or configure the secret to enable automatic generation.
    """
    if not HAS_GENAI or not GEMINI_API_KEY:
        return (
            "Explanation: (Set the GEMINI_API_KEY secret in your repo to enable "
            "automatic AI-generated explanations for every solution.)"
        )

    try:
        model = genai.GenerativeModel("gemini-pro")
        prompt = f"""You are an expert competitive-programming tutor.
Explain the following {lang_ext} LeetCode solution clearly and concisely.

Structure your answer as:
1. Approach – Summarise the algorithm / data structures used and why.
2. Complexity – State the time and space complexity with brief reasoning.
3. Code Walkthrough – Go through every key variable and each major step.

Format as plain text suitable for embedding in a source-code comment block
(no markdown fences, no bullet symbols that would break comment parsing).

Code:
{code}
"""
        response = model.generate_content(prompt)
        return response.text.strip()
    except Exception as exc:
        print(f"⚠️  Gemini API call failed: {exc}")
        return "Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)"

# ===========================================================================
# Comment-block generation
# ===========================================================================

def generate_comment_block(sub: dict, lang_ext: str, problem_number: str) -> str:
    """
    Build a structured comment header for the solution file.

    Contains:
      • Problem number & title
      • LeetCode URL
      • Date solved, runtime, and memory
      • AI-generated explanation (or placeholder)
    """
    title      = sub.get("title", "")
    slug       = sub.get("title_slug", "")
    timestamp  = sub.get("timestamp", 0)
    runtime    = sub.get("runtime", "N/A")
    memory     = sub.get("memory", "N/A")
    code       = sub.get("code") or ""

    try:
        date_str = datetime.datetime.fromtimestamp(int(timestamp)).strftime("%Y-%m-%d")
    except (TypeError, ValueError, OSError):
        date_str = "unknown"
    explanation = get_ai_explanation(code, lang_ext)

    info_lines = [
        f"Problem {problem_number}: {title}",
        f"URL     : https://leetcode.com/problems/{slug}/",
        f"Solved  : {date_str}",
        f"Runtime : {runtime}",
        f"Memory  : {memory}",
        "",
        explanation,
    ]

    # Pick the right comment syntax for the language
    if lang_ext in ("python3", "python"):
        start, end, prefix = '"""', '"""', ""
    elif lang_ext in (
        "cpp", "java", "c", "javascript", "typescript",
        "csharp", "kotlin", "swift", "dart", "golang", "scala", "rust",
    ):
        start, end, prefix = "/*", "*/", " * "
    else:
        # Hash-style (shell, Ruby, etc.)
        start, end, prefix = "", "", "# "

    lines = []
    if start:
        lines.append(start)
    for line in info_lines:
        lines.append(f"{prefix}{line}" if line else (prefix.rstrip() if prefix.strip() else ""))
    if end:
        lines.append(end)

    return "\n".join(lines) + "\n\n"

# ===========================================================================
# Local file helpers
# ===========================================================================

def get_existing_slugs() -> set:
    """
    Return the set of problem slugs that already have a file in problems/.

    Files are expected to follow the naming convention:
        {number}-{slug}.{ext}   e.g. 0001-two-sum.cpp
    """
    problems_dir = os.path.join(os.getcwd(), "problems")
    if not os.path.isdir(problems_dir):
        return set()

    slugs = set()
    for fname in os.listdir(problems_dir):
        if not os.path.isfile(os.path.join(problems_dir, fname)):
            continue
        # Strip extension, then strip leading "NNNN-" prefix if present
        stem, _ = os.path.splitext(fname)
        # Format: "0001-two-sum"  →  slug = "two-sum"
        parts = stem.split("-", 1)
        if len(parts) == 2 and parts[0].isdigit():
            slugs.add(parts[1])
        else:
            # Fallback for any legacy files that lack a numeric prefix
            slugs.add(stem)
    return slugs


def save_solution_locally(sub: dict) -> None:
    """
    Write a single accepted solution to problems/{number}-{slug}.{ext}
    and create a dedicated git commit for it.
    """
    slug     = sub["title_slug"]
    lang_ext = sub.get("lang", "txt")
    ext      = EXT_MAP.get(lang_ext, "txt")

    # Fetch the problem number from LeetCode's GraphQL API
    problem_number = get_problem_number(slug)

    filename = os.path.join("problems", f"{problem_number}-{slug}.{ext}")
    os.makedirs(os.path.dirname(filename), exist_ok=True)

    comment_block = generate_comment_block(sub, lang_ext, problem_number)
    code          = sub.get("code") or ""
    content       = comment_block + code

    with open(filename, "w", encoding="utf-8") as fh:
        fh.write(content)
    print(f"✅ Saved: {filename}")

    # --- Git commit ---
    commit_name = (
        os.getenv("COMMIT_NAME")
        or os.getenv("GIT_AUTHOR_NAME")
        or os.getenv("GITHUB_ACTOR")
        or LEETCODE_USERNAME
        or "LeetCode Sync"
    )
    actor = os.getenv("GITHUB_ACTOR")
    default_email = (
        f"{actor}@users.noreply.github.com" if actor else "noreply@github.com"
    )
    commit_email = (
        os.getenv("COMMIT_EMAIL")
        or os.getenv("GIT_AUTHOR_EMAIL")
        or default_email
    )

    try:
        subprocess.run(["git", "add", filename], check=True)
        author_flag = f"{commit_name} <{commit_email}>"
        commit_msg  = f"Add {problem_number}: {sub.get('title') or slug}"
        subprocess.run(
            [
                "git",
                "-c", f"user.name={commit_name}",
                "-c", f"user.email={commit_email}",
                "commit",
                "--author", author_flag,
                "-m", commit_msg,
            ],
            check=True,
        )
        print(f"📝 Committed: {filename}")
    except subprocess.CalledProcessError as exc:
        print(f"⚠️  Git commit failed for {filename}: {exc}")

# ===========================================================================
# Entry point
# ===========================================================================

def main() -> None:
    # --- Validate required secrets ---
    missing = []
    if not LEETCODE_SESSION:
        missing.append("LEETCODE_SESSION")
    if not LEETCODE_USERNAME:
        missing.append("LEETCODE_USERNAME")
    if missing:
        print(
            f"❌ Missing required secret(s): {', '.join(missing)}.\n"
            "   Configure them under: Repo Settings → Secrets and variables → Actions."
        )
        raise SystemExit(1)

    print("📥 Fetching submissions from LeetCode…")
    submissions = get_all_submissions(limit=500)
    print(f"   {len(submissions)} accepted submission(s) found.")

    already_saved = get_existing_slugs()
    saved_count   = 0

    for sub in submissions:
        slug = sub["title_slug"]
        if slug in already_saved:
            continue  # already in the repo

        save_solution_locally(sub)
        saved_count += 1

        if saved_count >= 2:
            # Only 2 new problems per daily run
            break

        # Small delay between problems to respect API rate limits
        time.sleep(1)

    if saved_count == 0:
        print("ℹ️  No new submissions to upload today.")
    else:
        print(f"🎉 Done – {saved_count} new problem(s) saved.")


if __name__ == "__main__":
    main()
