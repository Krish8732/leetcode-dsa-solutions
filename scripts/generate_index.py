import os
import re
import urllib.parse
import subprocess

REPO_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
INDEX_PATH = os.path.join(REPO_ROOT, "SOLUTIONS_INDEX.md")

DIFFICULTY_BADGES = {
    "Easy": "🟢 Easy",
    "Medium": "🟡 Medium",
    "Hard": "🔴 Hard"
}


def parse_solution_file(rel_path):
    full_path = os.path.join(REPO_ROOT, rel_path)
    parts = rel_path.replace("\\", "/").split("/")
    if len(parts) < 3:
        return None

    topic = parts[0]
    difficulty = parts[1]
    filename = parts[2]

    m = re.match(r"^(\d+)_(.+)\.cpp$", filename)
    if not m:
        return None

    number = int(m.group(1))
    title = m.group(2).replace("_", " ")

    lc_link = ""
    concepts = ""

    try:
        with open(full_path, "r", encoding="utf-8", errors="ignore") as f:
            for _ in range(15):
                line = f.readline()
                if not line:
                    break
                if line.startswith("// LeetCode:"):
                    lc_link = line.replace("// LeetCode:", "").strip()
                elif line.startswith("// Concepts:"):
                    concepts = line.replace("// Concepts:", "").strip()
    except Exception:
        pass

    encoded_rel_path = urllib.parse.quote(rel_path.replace("\\", "/"))

    return {
        "number": number,
        "title": title,
        "difficulty": difficulty,
        "topic": topic,
        "concepts": concepts or "-",
        "lc_link": lc_link or f"https://leetcode.com/problemset/all/?search={number}",
        "file_link": f"./{encoded_rel_path}"
    }


def generate_index():
    # Only index committed solutions from git
    try:
        git_files = subprocess.check_output(
            ["git", "ls-tree", "-r", "HEAD", "--name-only"],
            cwd=REPO_ROOT,
            text=True,
            encoding="utf-8"
        ).splitlines()
    except Exception:
        git_files = []

    solutions = []
    for path in git_files:
        if path.endswith(".cpp"):
            info = parse_solution_file(path)
            if info:
                solutions.append(info)

    # Sort numerically by problem number
    solutions.sort(key=lambda x: x["number"])

    lines = [
        "# 📚 Solutions Index & Search Directory",
        "",
        f"> Quick-reference table of all **{len(solutions)}** solved and committed problems in this repository.",
        "",
        "| # | Problem Name | Difficulty | Category | Concepts | Code |",
        "| :---: | :--- | :---: | :--- | :--- | :---: |"
    ]

    for s in solutions:
        diff_badge = DIFFICULTY_BADGES.get(s["difficulty"], s["difficulty"])
        problem_link = f"[{s['title']}]({s['lc_link']})"
        code_link = f"[Solution]({s['file_link']})"
        lines.append(
            f"| {s['number']} | {problem_link} | {diff_badge} | {s['topic']} | {s['concepts']} | {code_link} |"
        )

    with open(INDEX_PATH, "w", encoding="utf-8") as f:
        f.write("\n".join(lines) + "\n")

    print(f"Successfully generated SOLUTIONS_INDEX.md with {len(solutions)} indexed problems.")


if __name__ == "__main__":
    generate_index()
