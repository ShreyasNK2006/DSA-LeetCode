"""
annotate_existing.py
====================
Utility script to retroactively add (or refresh) the structured comment
header on every file already present in problems/.

Run this manually whenever you want to back-fill or update explanations,
for example after adding a GEMINI_API_KEY for the first time.

Usage:
    python3 annotate_existing.py

Required environment variables (same as leetcode_to_github.py):
    LEETCODE_SESSION   – LeetCode session cookie
    LEETCODE_USERNAME  – your LeetCode username
    GEMINI_API_KEY     – (optional) enables AI-generated explanations
"""

import os
import subprocess
import time

from leetcode_to_github import (
    get_all_submissions,
    get_problem_number,
    generate_comment_block,
    LEETCODE_USERNAME,
    GEMINI_API_KEY,
)


def commit_file(filepath: str, msg: str) -> None:
    """Stage and commit a single file."""
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
        subprocess.run(["git", "add", filepath], check=True)
        author_flag = f"{commit_name} <{commit_email}>"
        subprocess.run(
            [
                "git",
                "-c", f"user.name={commit_name}",
                "-c", f"user.email={commit_email}",
                "commit",
                "--author", author_flag,
                "-m", msg,
            ],
            check=True,
        )
        print(f"📝 Committed: {filepath}")
    except subprocess.CalledProcessError as exc:
        print(f"⚠️  Git commit failed for {filepath}: {exc}")


def strip_existing_header(content: str) -> str:
    """
    Remove a previously-generated comment header from a solution file so that
    it can be replaced with an updated one.

    Handles three comment styles:
      • C-style block comments  /* … */
      • Python docstrings        \"\"\" … \"\"\"
      • Hash-line comments       # Title / Solved on …
    """
    stripped = content.strip()

    if stripped.startswith("/*"):
        end_idx = content.find("*/")
        if end_idx != -1:
            return content[end_idx + 2:].lstrip()

    elif stripped.startswith('"""'):
        end_idx = content.find('"""', 3)
        if end_idx != -1:
            return content[end_idx + 3:].lstrip()

    else:
        # Old hash-comment header: "# Title\nSolved on …\n"
        lines = content.splitlines()
        if lines and lines[0].startswith("# ") and len(lines) > 1 and "Solved" in lines[1]:
            return "\n".join(lines[2:]).lstrip()

    return content  # nothing to strip


def annotate_existing() -> None:
    print("📥 Fetching submissions to build slug → submission map…")
    submissions = get_all_submissions(limit=2000)
    print(f"   {len(submissions)} submission(s) fetched.")

    # Most-recent accepted submission wins (list is oldest→newest after reverse)
    sub_map = {}
    for sub in submissions:
        sub_map[sub["title_slug"]] = sub

    problems_dir = os.path.join(os.getcwd(), "problems")
    if not os.path.isdir(problems_dir):
        print("No problems/ directory found – nothing to annotate.")
        return

    files = sorted(
        f for f in os.listdir(problems_dir)
        if os.path.isfile(os.path.join(problems_dir, f))
    )

    for filename in files:
        filepath = os.path.join(problems_dir, filename)
        stem, _ext = os.path.splitext(filename)

        # Derive slug from filename: "0001-two-sum" → "two-sum"
        parts = stem.split("-", 1)
        if len(parts) == 2 and parts[0].isdigit():
            slug = parts[1]
        else:
            slug = stem  # legacy name without number prefix

        if slug not in sub_map:
            print(f"⚠️  No submission found for '{filename}' – skipping.")
            continue

        sub = sub_map[slug]
        lang_ext = sub.get("lang", "txt")

        with open(filepath, "r", encoding="utf-8") as fh:
            content = fh.read()

        # --- Determine whether re-annotation is needed ---
        already_annotated = (
            "Runtime :" in content[:600] and "Memory  :" in content[:600]
        )
        has_placeholder = (
            "Set the GEMINI_API_KEY secret" in content[:2000]
            or "AI generation failed" in content[:2000]
        )
        has_real_explanation = (
            "Approach" in content[:2000] or "Complexity" in content[:2000]
        ) and not has_placeholder

        if already_annotated and has_real_explanation:
            print(f"ℹ️  {filename}: already annotated with explanation – skipping.")
            continue

        if already_annotated and not GEMINI_API_KEY:
            print(f"ℹ️  {filename}: already annotated, no API key to add explanation – skipping.")
            continue

        # --- Fetch problem number (re-use from filename if available) ---
        if len(parts) == 2 and parts[0].isdigit():
            problem_number = parts[0]
        else:
            problem_number = get_problem_number(slug)

        # --- Strip existing header so we don't double-annotate ---
        clean_content = strip_existing_header(content)

        new_block    = generate_comment_block(sub, lang_ext, problem_number)
        final_content = new_block + clean_content

        with open(filepath, "w", encoding="utf-8") as fh:
            fh.write(final_content)

        print(f"✅ Annotated: {filename}")
        commit_file(filepath, f"Annotate {filename} with explanation header")

        # Gemini free tier: ~15 RPM → wait 4 s between calls
        if GEMINI_API_KEY:
            print("⏳ Waiting 4 s for API rate limit…")
            time.sleep(4)


if __name__ == "__main__":
    annotate_existing()
