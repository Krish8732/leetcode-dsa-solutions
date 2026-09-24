import os
import re
import subprocess

REPO_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EASY_TRACKER = os.path.join(REPO_ROOT, "EASY_PROBLEMS_TRACKER.md")
MEDIUM_HARD_TRACKER = os.path.join(REPO_ROOT, "MEDIUM_HARD_PROBLEMS_TRACKER.md")


def get_committed_solutions():
    """Returns set of problem numbers that are committed in git (tracking main)."""
    try:
        git_files = subprocess.check_output(
            ["git", "ls-tree", "-r", "HEAD", "--name-only"],
            cwd=REPO_ROOT,
            text=True,
            encoding="utf-8"
        ).splitlines()
    except Exception as e:
        print(f"Error querying git: {e}")
        return set()

    committed_numbers = set()
    for path in git_files:
        if path.endswith(".cpp"):
            filename = os.path.basename(path)
            match = re.match(r"^(\d+)_", filename)
            if match:
                committed_numbers.add(match.group(1))

    return committed_numbers


def sync_easy_tracker(committed_nums):
    if not os.path.exists(EASY_TRACKER):
        return

    with open(EASY_TRACKER, "r", encoding="utf-8") as f:
        content = f.read()

    lines = content.splitlines()
    new_lines = []
    checked_in_roadmap = 0
    total_in_roadmap = 0

    for line in lines:
        match = re.match(r"^- \[([ xX])\] `(\d+)\.", line)
        if match:
            total_in_roadmap += 1
            num = match.group(2)
            if num in committed_nums:
                line = re.sub(r"^- \[([ xX])\]", "- [x]", line)
                checked_in_roadmap += 1
            else:
                line = re.sub(r"^- \[([ xX])\]", "- [ ]", line)

        new_lines.append(line)

    with open(EASY_TRACKER, "w", encoding="utf-8") as f:
        f.write("\n".join(new_lines) + "\n")

    print(f"Synced EASY_PROBLEMS_TRACKER.md: {checked_in_roadmap}/{total_in_roadmap} roadmap items verified.")


def sync_medium_hard_tracker(committed_nums):
    if not os.path.exists(MEDIUM_HARD_TRACKER):
        return

    with open(MEDIUM_HARD_TRACKER, "r", encoding="utf-8") as f:
        content = f.read()

    lines = content.splitlines()
    new_lines = []
    med_count = 0
    hard_count = 0
    current_section = ""

    for line in lines:
        if "## 🟡 Medium Problems" in line:
            current_section = "Medium"
        elif "## 🔴 Hard Problems" in line:
            current_section = "Hard"

        match = re.match(r"^- \[([ xX])\] \[(\d+)\.", line)
        if match:
            num = match.group(2)
            if num in committed_nums:
                line = re.sub(r"^- \[([ xX])\]", "- [x]", line)
                if current_section == "Medium":
                    med_count += 1
                elif current_section == "Hard":
                    hard_count += 1
            else:
                line = re.sub(r"^- \[([ xX])\]", "- [ ]", line)

        new_lines.append(line)

    # Update summary header if present
    content = "\n".join(new_lines) + "\n"
    total_committed = med_count + hard_count
    content = re.sub(
        r"\*\*Solved & Committed in Repo:\*\* \d+ \(Medium: \d+, Hard: \d+\)",
        f"**Solved & Committed in Repo:** {total_committed} (Medium: {med_count}, Hard: {hard_count})",
        content
    )

    with open(MEDIUM_HARD_TRACKER, "w", encoding="utf-8") as f:
        f.write(content)

    print(f"Synced MEDIUM_HARD_PROBLEMS_TRACKER.md: {total_committed} problems marked (Medium: {med_count}, Hard: {hard_count}).")


def main():
    committed = get_committed_solutions()
    print(f"Total committed solution files found in git: {len(committed)}")
    sync_easy_tracker(committed)
    sync_medium_hard_tracker(committed)


if __name__ == "__main__":
    main()
