import requests, os, json, base64, datetime, time, subprocess

try:
    import google.generativeai as genai
    HAS_GENAI = True
except ImportError:
    HAS_GENAI = False

LEETCODE_USERNAME = os.getenv("LEETCODE_USERNAME")
REPO_NAME = os.getenv("REPO_NAME")
GITHUB_TOKEN = os.getenv("GITHUB_TOKEN")
LEETCODE_SESSION = os.getenv("LEETCODE_SESSION")
GEMINI_API_KEY = os.getenv("GEMINI_API_KEY")

if HAS_GENAI and GEMINI_API_KEY:
    genai.configure(api_key=GEMINI_API_KEY)

# We'll write files locally and let the workflow commit them
HEADERS = {
    "cookie": f"LEETCODE_SESSION={LEETCODE_SESSION}",
    "User-Agent": "Mozilla/5.0",
}

def get_all_submissions(limit=200):
    """Fetch accepted submissions with code from LeetCode."""
    url = "https://leetcode.com/api/submissions/"
    submissions = []
    offset = 0

    while len(submissions) < limit:
        res = requests.get(f"{url}?offset={offset}&limit=20", headers=HEADERS)
        if res.status_code != 200:
            print("❌ Failed to fetch submissions:", res.text)
            break
        data = res.json()
        for sub in data.get("submissions_dump", []):
            if sub.get("status_display") == "Accepted" and sub.get("code"):
                # Only take accepted submissions that include code
                submissions.append(sub)
        if not data.get("has_next"):
            break
        offset += 20
        time.sleep(0.5)

    submissions.reverse()  # oldest → newest
    return submissions

def get_existing_files_local():
    """List uploaded problem files in local problems/ folder (by slug)."""
    problems_dir = os.path.join(os.getcwd(), "problems")
    if not os.path.isdir(problems_dir):
        return []
    return [os.path.splitext(f)[0] for f in os.listdir(problems_dir) if os.path.isfile(os.path.join(problems_dir, f))]

def get_ai_explanation(code, lang_ext):
    """Generates an explanation using Gemini API if available."""
    if not HAS_GENAI or not GEMINI_API_KEY:
        return "Explanation: (Configure GEMINI_API_KEY to enable AI explanations)"
    
    try:
        model = genai.GenerativeModel('gemini-pro')
        prompt = f"""
        Explain the following {lang_ext} solution for a LeetCode problem.
        1. Approach: A concise summary of the algorithm/logic.
        2. Variables: Explain the purpose of key variables.
        
        Keep it concise and formatted as a comment block content.
        
        Code:
        {code}
        """
        response = model.generate_content(prompt)
        return response.text.strip()
    except Exception as e:
        print(f"⚠️ AI Generation failed: {e}")
        return "Explanation: (AI generation failed)"

def generate_comment_block(sub, lang_ext):
    """Generates a comment block with submission details."""
    title = sub.get("title")
    timestamp = sub.get("timestamp")
    runtime = sub.get("runtime")
    memory = sub.get("memory")
    code = sub.get("code") or ""
    
    date_str = datetime.datetime.fromtimestamp(int(timestamp)).strftime('%Y-%m-%d')
    
    explanation = get_ai_explanation(code, lang_ext)
    
    info_lines = [
        f"Problem: {title}",
        f"Solved on: {date_str}",
        f"Runtime: {runtime}",
        f"Memory: {memory}",
        "",
        explanation
    ]
    
    # Determine comment syntax
    if lang_ext in ["python3", "python"]:
        start, end, prefix = '"""', '"""', ""
    elif lang_ext in ["cpp", "java", "c", "javascript", "typescript", "csharp", "kotlin", "swift", "dart", "golang", "scala"]:
        start, end, prefix = "/*", "*/", " * "
    else:
        # Default to hash comments if unknown
        start, end, prefix = "", "", "# "
        
    comment = []
    if start:
        comment.append(start)
    
    for line in info_lines:
        comment.append(f"{prefix}{line}")
        
    if end:
        comment.append(end)
        
    return "\n".join(comment) + "\n\n"

def save_solution_locally(sub):
    """Save a single problem solution to the local workspace under problems/."""
    slug = sub["title_slug"]
    lang_ext = sub.get("lang")
    ext_map = {
        "python3": "py",
        "cpp": "cpp",
        "java": "java",
        "c": "c",
        "javascript": "js",
    }
    ext = ext_map.get(lang_ext, "txt")

    filename = os.path.join("problems", f"{slug}.{ext}")
    os.makedirs(os.path.dirname(filename), exist_ok=True)

    # Generate comment block
    comment_block = generate_comment_block(sub, lang_ext)
    code = sub.get("code") or ""
    content = comment_block + code

    with open(filename, "w", encoding="utf-8") as f:
        f.write(content)
    print(f"✅ Saved locally: {filename}")

    # Create a separate commit for this file
    commit_name = os.getenv("COMMIT_NAME") or os.getenv("GIT_AUTHOR_NAME") or os.getenv("GITHUB_ACTOR") or LEETCODE_USERNAME or "LeetCode Sync"
    # Prefer explicit COMMIT_EMAIL; fall back to GitHub noreply if actor is present
    actor = os.getenv("GITHUB_ACTOR")
    default_noreply = f"{actor}@users.noreply.github.com" if actor else "noreply@github.com"
    commit_email = os.getenv("COMMIT_EMAIL") or os.getenv("GIT_AUTHOR_EMAIL") or default_noreply

    try:
        subprocess.run(["git", "add", filename], check=True)
        author_flag = f"{commit_name} <{commit_email}>"
        msg = str(sub.get('title') or slug)
        # Use -c to ensure committer identity even if global config differs
        subprocess.run([
            "git",
            "-c", f"user.name={commit_name}",
            "-c", f"user.email={commit_email}",
            "commit",
            "--author", author_flag,
            "-m", msg,
        ], check=True)
        print(f"📝 Committed: {filename}")
    except subprocess.CalledProcessError as e:
        # If nothing to commit (shouldn't happen when adding a new file), just log
        print(f"⚠️ Git commit skipped/failed for {filename}: {e}")

def main():
    # Basic validation for required secrets; fail fast so the workflow shows a clear error
    missing = []
    if not LEETCODE_SESSION:
        missing.append("LEETCODE_SESSION")
    if not LEETCODE_USERNAME:
        missing.append("LEETCODE_USERNAME")
    if missing:
        print(f"❌ Missing required secret(s): {', '.join(missing)}. Configure them in Repo Settings → Secrets and variables → Actions.")
        raise SystemExit(1)

    subs = get_all_submissions(limit=200)
    uploaded = get_existing_files_local()
    count = 0

    for sub in subs:
        slug = sub["title_slug"]
        if slug not in uploaded:
            save_solution_locally(sub)
            count += 1
        if count >= 2:  # keep your existing limit behaviour
            break

    if count == 0:
        if uploaded:
            print("ℹ️ No new submissions to upload (all already uploaded).")
        else:
            print("ℹ️ No submissions found with code from LeetCode.")

if __name__ == "__main__":
    main()
