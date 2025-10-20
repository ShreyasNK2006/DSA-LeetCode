import requests, os, json, base64, datetime, time

LEETCODE_USERNAME = os.getenv("LEETCODE_USERNAME")
REPO_NAME = os.getenv("REPO_NAME")
GITHUB_TOKEN = os.getenv("GITHUB_TOKEN")
LEETCODE_SESSION = os.getenv("LEETCODE_SESSION")

GITHUB_API = "https://api.github.com"

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
            if sub["status_display"] == "Accepted":
                submissions.append(sub)
        if not data.get("has_next"):
            break
        offset += 20
        time.sleep(0.5)

    # ✅ Reverse to get oldest → newest order
    submissions.reverse()
    return submissions


def get_existing_files():
    """List uploaded problem files (by slug)."""
    url = f"{GITHUB_API}/repos/{REPO_NAME}/contents/problems"
    headers = {"Authorization": f"token {GITHUB_TOKEN}"}
    r = requests.get(url, headers=headers)
    if r.status_code == 200:
        return [file["name"].split(".")[0] for file in r.json()]
    return []


def commit_to_github(sub):
    """Commit a single problem solution to GitHub."""
    slug = sub["title_slug"]
    lang_ext = sub["lang"]
    ext_map = {
        "python3": "py",
        "cpp": "cpp",
        "java": "java",
        "c": "c",
        "javascript": "js",
    }
    ext = ext_map.get(lang_ext, "txt")

    filename = f"problems/{slug}.{ext}"
    date = datetime.datetime.fromtimestamp(int(sub["timestamp"]))
    header = f"# {sub['title']}\nSolved on {date.strftime('%Y-%m-%d')}\n\n"
    code = header + sub["code"]

    content_b64 = base64.b64encode(code.encode()).decode()

    api_url = f"{GITHUB_API}/repos/{REPO_NAME}/contents/{filename}"
    headers = {"Authorization": f"token {GITHUB_TOKEN}"}
    data = {"message": f"Add {sub['title']} solution", "content": content_b64}

    r = requests.put(api_url, headers=headers, json=data)
    if r.status_code in [200, 201]:
        print(f"✅ Uploaded: {sub['title']}")
    else:
        print(f"❌ Failed: {sub['title']} ({r.status_code})")


def main():
    subs = get_all_submissions(limit=200)
    uploaded = get_existing_files()
    count = 0

    # Go oldest → newest
    for sub in subs:
        slug = sub["title_slug"]
        if slug not in uploaded:
            commit_to_github(sub)
            count += 1
        if count >= 2:
            break

    if count == 0:
        print("🎉 All problems already uploaded!")


if __name__ == "__main__":
    main()
