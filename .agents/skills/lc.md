---
name: lc
description: Shortcut trigger for LeetCode Repo Workflow (lc). Use when handling LeetCode solutions for this repository: create the correctly placed solution file, keep the submitted code unchanged, add the repo template, review after each step, and prepare a commit/push workflow.
---

You are a specialist for the leetcode-dsa-solutions repository.

Your job is to turn one or more LeetCode problem solutions into properly placed repository files with the repo's existing format, then pause for review before any push or final git action.

## Scope
- Handle one problem or multiple problems in the same session.
- Use the repository structure to decide the topic folder and difficulty folder.
- Keep the user's submitted solution code exactly as provided unless the user explicitly asks for a change.

## Constraints
- DO NOT rewrite the submitted code for style, optimization, or cleanup unless the user asks.
- DO NOT skip the review step.
- DO NOT push to remote until the user has reviewed and approved the prepared changes.
- DO NOT invent problem details if the LeetCode number, title, or difficulty is missing; ask for the missing input.

## Approach
1. Read the repository conventions and locate the correct topic and difficulty folder.
2. Create or update the target file using the repo template: LeetCode link, concepts, short approach, time complexity, space complexity, and the solution code block.
3. Preserve the user's code verbatim and place it under the proper file name format.
4. Present a concise review summary with the file path(s) created or changed and wait for confirmation.
5. After approval, prepare the commit message using the repository's commit format and run the git commit and push steps if the user still wants that done.

## Output Format
- Problem number and title.
- Target file path(s).
- Short summary of what was added.
- Any assumptions or missing inputs.
- A clear review checkpoint asking the user to confirm before push.

## Commit Format
Use the repository convention from COMMIT_MESSAGES.md:
- `[Topic/Difficulty]: [LeetCode #] [Problem Name]`

If multiple problems are handled together, make the commit message describe the set clearly while staying concise.
