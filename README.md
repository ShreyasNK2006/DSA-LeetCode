# 💻 LeetCode Solutions — Auto-Sync

A repository that **automatically fetches and commits my accepted LeetCode submissions** daily, complete with structured comment headers and optional AI-generated explanations.

Solutions are added in chronological order (oldest → newest), **2 problems per day**, by a GitHub Actions workflow.

---

## 📁 File Naming Convention

Every solution file follows this pattern:

```
problems/{NNNN}-{problem-slug}.{ext}
```

For example:
- `problems/0001-two-sum.cpp`
- `problems/0070-climbing-stairs.py`

The four-digit zero-padded prefix ensures files sort in problem-number order automatically.

---

## 🤖 Automation

### `leetcode_to_github.py`

The main sync script. On each run it:

1. Fetches all accepted submissions from LeetCode (oldest → newest).
2. Checks which problems are already committed to `problems/`.
3. Saves the next **2 new** problems, each with a structured comment header.
4. Creates a separate, descriptive git commit for each problem.

### `annotate_existing.py`

A utility to retroactively add or refresh the comment header on files that are already in `problems/`. Useful after configuring a Gemini API key so that older solutions also get AI explanations.

Run it from the **Actions** tab → *Annotate Existing Solutions* → *Run workflow*.

---

## ⚙️ Setup

### 1 — Fork / clone this repository

### 2 — Configure GitHub Secrets

Go to **Settings → Secrets and variables → Actions → New repository secret** and add:

| Secret name        | Required | Description |
|--------------------|----------|-------------|
| `LEETCODE_SESSION` | ✅ Yes   | Value of the `LEETCODE_SESSION` cookie from your browser after logging in to leetcode.com |
| `LEETCODE_USERNAME`| ✅ Yes   | Your LeetCode username |
| `GEMINI_API_KEY`   | Optional | Google Gemini API key — enables AI-generated code explanations. Get one free at [aistudio.google.com](https://aistudio.google.com/app/apikey) |

> **How to get LEETCODE_SESSION:** Log in to leetcode.com, open DevTools → Application → Cookies, and copy the value of the `LEETCODE_SESSION` cookie.

### 3 — The workflow runs automatically

The `daily.yml` workflow triggers every day at **02:00 UTC (07:30 AM IST)** and commits 2 new problems. You can also trigger it manually from the Actions tab.

---

## 🧠 Comment Header Format

Each solution file starts with a header like this (C++ shown):

```cpp
/*
 * Problem 0001: Two Sum
 * URL     : https://leetcode.com/problems/two-sum/
 * Solved  : 2024-05-10
 * Runtime : 3 ms
 * Memory  : 10.4 MB
 *
 * Approach – Use a hash map to store each number and its index.
 *   For every element x, check if (target - x) is already in the map.
 *   If yes, return the two indices. Otherwise, store x in the map.
 * Complexity – Time O(n), Space O(n).
 * Code Walkthrough – ...
 */
```

If `GEMINI_API_KEY` is not configured, the explanation section shows a placeholder instead.

---

## 🗂️ Workflows

| Workflow | Trigger | What it does |
|----------|---------|--------------|
| `daily.yml` | Daily cron (02:00 UTC) + manual | Fetches & commits 2 new LeetCode solutions |
| `annotate.yml` | Manual only | Re-annotates all existing solutions in `problems/` |
