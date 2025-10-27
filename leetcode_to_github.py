import requests, os, json, base64, datetime, time, subprocess

LEETCODE_USERNAME = os.getenv("LEETCODE_USERNAME")
REPO_NAME = os.getenv("REPO_NAME")
GITHUB_TOKEN = os.getenv("GITHUB_TOKEN")
LEETCODE_SESSION = os.getenv("LEETCODE_SESSION")

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
        for sub in data["submissions_dump"]:
            if sub.get("status_display") == "Accepted":
                # Ensure the submission contains code; older dumps sometimes don't include it
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

    date = datetime.datetime.fromtimestamp(int(sub.get("timestamp", time.time())))
    header = f"# {sub.get('title')}\nSolved on {date.strftime('%Y-%m-%d')}\n\n"
    code = sub.get("code") or ""
    content = header + code

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
        print("🎉 All problems already uploaded!")

if __name__ == "__main__":
    main()
