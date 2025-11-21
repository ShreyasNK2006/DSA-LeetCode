💻 LeetCode Solutions in C++
A repository dedicated to tracking my progress on LeetCode challenges. All solutions are written in C++ and are optimized for time and space complexity.

The primary goal of this project is to strengthen my skills in data structures, algorithms, and efficient C++ programming.

## 🤖 Automation Scripts

This repository includes scripts to automate the syncing of LeetCode solutions and enhance them with metadata.

### `leetcode_to_github.py`
Automatically fetches your latest accepted submissions from LeetCode and saves them to the `problems/` directory.
- Adds a structured comment header with:
  - Problem Title
  - Date Solved
  - Runtime & Memory Usage
  - Placeholder for Explanation
- Commits each new solution automatically.

### `annotate_existing.py`
A utility script to retroactively add the new metadata header to existing files in `problems/`.
- Matches existing files to your LeetCode submission history.
- Updates the file with the new header format.
- Creates a separate commit for each updated file.

**Usage:**
Ensure you have the required environment variables set (`LEETCODE_SESSION`, `LEETCODE_USERNAME`, etc.) and run:
```bash
python3 annotate_existing.py
```
