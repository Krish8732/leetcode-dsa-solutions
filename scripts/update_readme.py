import os
import re
import urllib.parse

# 21 DSA Topics listed in README
TOPICS = [
    "Arrays",
    "Backtracking",
    "Bit_Magic",
    "Design",
    "DP",
    "Graph",
    "Greedy",
    "HashMap",
    "HashSet",
    "Heap",
    "Line Sweep Technique",
    "Linked List",
    "Mathematical",
    "Queue",
    "Recursion",
    "Segment Tree",
    "Sliding Window",
    "Stack",
    "Strings",
    "Tree",
    "Trie",
]

DIFFICULTIES = ["Easy", "Medium", "Hard"]
REPO_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
README_PATH = os.path.join(REPO_ROOT, "README.md")


def count_solutions(topic_dir, difficulty):
    diff_path = os.path.join(REPO_ROOT, topic_dir, difficulty)
    if not os.path.exists(diff_path):
        return 0
    return len([f for f in os.listdir(diff_path) if f.endswith(".cpp")])


def generate_table_and_totals():
    total_easy = 0
    total_medium = 0
    total_hard = 0

    table_rows = [
        "| Topic | Easy | Medium | Hard | Total |",
        "|-------|------|--------|------|-------|",
    ]

    for topic in TOPICS:
        easy = count_solutions(topic, "Easy")
        medium = count_solutions(topic, "Medium")
        hard = count_solutions(topic, "Hard")
        total = easy + medium + hard

        total_easy += easy
        total_medium += medium
        total_hard += hard

        encoded_topic = urllib.parse.quote(topic)
        topic_link = f"[{topic}](./{encoded_topic})"
        table_rows.append(
            f"| {topic_link} | {easy} | {medium} | {hard} | {total} |"
        )

    grand_total = total_easy + total_medium + total_hard
    table_rows.append(
        f"| **Total** | **{total_easy}** | **{total_medium}** | **{total_hard}** | **{grand_total}** |"
    )

    return "\n".join(table_rows), grand_total


def update_readme():
    with open(README_PATH, "r", encoding="utf-8") as f:
        content = f.read()

    new_table, grand_total = generate_table_and_totals()

    # 1. Update Badge
    badge_pattern = r"(https://img\.shields\.io/badge/Problems%20Solved-)\d+(-brightgreen\?style=for-the-badge&logo=leetcode)"
    updated_content = re.sub(badge_pattern, f"\\g<1>{grand_total}\\g<2>", content)

    # 2. Update Table (from | Topic | Easy | ... to end of table)
    table_pattern = r"\| Topic \| Easy \| Medium \| Hard \| Total \|.*?\n\| \*\*Total\*\* \| \*\*\d+\*\* \| \*\*\d+\*\* \| \*\*\d+\*\* \| \*\*\d+\*\* \|"
    updated_content = re.sub(table_pattern, new_table, updated_content, flags=re.DOTALL)

    with open(README_PATH, "w", encoding="utf-8") as f:
        f.write(updated_content)

    print(f"Successfully updated README.md (Total Solved: {grand_total})")


if __name__ == "__main__":
    update_readme()
