import os
import subprocess
import datetime
import time
from leetcode_to_github import get_all_submissions, generate_comment_block, LEETCODE_USERNAME, GEMINI_API_KEY

def commit_file(filepath, msg):
    """Commits a single file with the given message."""
    commit_name = os.getenv("COMMIT_NAME") or os.getenv("GIT_AUTHOR_NAME") or os.getenv("GITHUB_ACTOR") or LEETCODE_USERNAME or "LeetCode Sync"
    actor = os.getenv("GITHUB_ACTOR")
    default_noreply = f"{actor}@users.noreply.github.com" if actor else "noreply@github.com"
    commit_email = os.getenv("COMMIT_EMAIL") or os.getenv("GIT_AUTHOR_EMAIL") or default_noreply

    try:
        subprocess.run(["git", "add", filepath], check=True)
        author_flag = f"{commit_name} <{commit_email}>"
        subprocess.run([
            "git",
            "-c", f"user.name={commit_name}",
            "-c", f"user.email={commit_email}",
            "commit",
            "--author", author_flag,
            "-m", msg,
        ], check=True)
        print(f"📝 Committed: {filepath}")
    except subprocess.CalledProcessError as e:
        print(f"⚠️ Git commit skipped/failed for {filepath}: {e}")

def annotate_existing():
    print("Fetching submissions...")
    # Fetch enough to cover history
    submissions = get_all_submissions(limit=2000) 
    print(f"Fetched {len(submissions)} submissions.")
    
    # Map slug -> submission (prefer newest accepted)
    sub_map = {}
    for sub in submissions:
        sub_map[sub['title_slug']] = sub
        
    problems_dir = os.path.join(os.getcwd(), "problems")
    if not os.path.isdir(problems_dir):
        print("No problems directory found.")
        return

    files = [f for f in os.listdir(problems_dir) if os.path.isfile(os.path.join(problems_dir, f))]
    
    for filename in files:
        filepath = os.path.join(problems_dir, filename)
        slug, ext = os.path.splitext(filename)
        
        if slug not in sub_map:
            print(f"⚠️ No submission found for {filename}, skipping.")
            continue
            
        sub = sub_map[slug]
        
        with open(filepath, "r", encoding="utf-8") as f:
            content = f.read()
            
        new_block = generate_comment_block(sub, sub['lang'])
        
        # Check if already annotated with the new style
        # The new style starts with comment markers.
        # We can check for "Runtime:" and "Memory:" in the first few lines
        is_annotated = "Runtime:" in content[:500] and "Memory:" in content[:500]
        
        # Check if it has a REAL explanation, not the placeholder
        has_placeholder = "Explanation: (Configure GEMINI_API_KEY" in content[:1500] or "Explanation: (AI generation failed)" in content[:1500]
        has_explanation = ("Approach:" in content[:1500] or "Explanation:" in content[:1500]) and not has_placeholder
        
        if is_annotated and has_explanation:
             print(f"ℹ️ {filename} seems already annotated with explanation.")
             continue
             
        if is_annotated and not GEMINI_API_KEY:
             print(f"ℹ️ {filename} already annotated (no API key to add explanation).")
             continue

        # Remove old header if present
        # Old header format:
        # # Title
        # Solved on ...
        # <blank>
        
        clean_content = content
        
        # Strip existing block comment if it exists (for re-annotation)
        if is_annotated:
            if content.strip().startswith("/*"):
                end_idx = content.find("*/")
                if end_idx != -1:
                    clean_content = content[end_idx+2:].lstrip()
            elif content.strip().startswith('"""'):
                # Find the second occurrence of """
                end_idx = content.find('"""', 3)
                if end_idx != -1:
                    clean_content = content[end_idx+3:].lstrip()
        
        # Fallback for the very old header format
        lines = clean_content.splitlines()
        if len(lines) > 0 and lines[0].startswith("# "):
            if len(lines) > 1 and "Solved on" in lines[1]:
                # Remove the first 2 lines and any following blank lines
                clean_content = "\n".join(lines[2:]).lstrip()
            elif len(lines) > 2 and "Solved on" in lines[2]:
                 # Sometimes there might be an extra line?
                 clean_content = "\n".join(lines[3:]).lstrip()
        
        final_content = new_block + clean_content
        
        final_content = new_block + clean_content
        
        with open(filepath, "w", encoding="utf-8") as f:
            f.write(final_content)
            
        print(f"✅ Annotated {filename}")
        commit_file(filepath, f"Annotate {filename} with explanation header")
        
        # Rate limiting for Gemini API (free tier is ~15 RPM, so 4s delay is safe)
        if GEMINI_API_KEY:
            print("⏳ Waiting 4s for API rate limit...")
            time.sleep(4)

if __name__ == "__main__":
    annotate_existing()
