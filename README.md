# LeetCode DSA Solutions

This repository is a clean collection of LeetCode solutions organized by topic and difficulty. Each file is meant to stay close to the code you submit on LeetCode: minimal notes, minimal clutter.

## 📁 Repository Structure

Solutions are organized by **21 major DSA topics**, each containing problems categorized by **difficulty levels** (Easy, Medium, Hard):

```
leetcode-dsa-solutions/
├── Arrays/
├── Strings/
├── Linked List/
├── Stack/
├── Queue/
├── Tree/
├── Graph/
├── Heap/
├── HashMap/
├── HashSet/
├── DP/
├── Greedy/
├── Backtracking/
├── Recursion/
├── Sliding Window/
├── Bit_Magic/
├── Mathematical/
├── Trie/
├── Segment Tree/
├── Design/
└── Line Sweep Technique/
```

Each topic folder contains `Easy/`, `Medium/`, and `Hard/` subdirectories with individual problem solutions.

## 📝 File Naming Convention

Files are named with the following format:
```
{LeetCode_Problem_Number}_{Problem_Name}.{extension}
```

**Example:**
```
938_RangeSumOfBST.cpp
```

## 💡 Solution Format

Each solution file includes:
- **LeetCode link**: the problem URL at the top
- **DSA concepts**: the main patterns used
- **Approach**: short explanation of the idea
- **Time Complexity** and **Space Complexity**: two short lines
- **Solution class code**: only the `class Solution` block you submitted on LeetCode

Example layout:
```cpp
// LeetCode: https://leetcode.com/problems/range-sum-of-bst/
// Concepts: DFS, BST pruning
// Approach: Traverse only the branches that can still contain valid values.
// TC: O(n) | SC: O(h)

class Solution {
public:
   int rangeSumBST(TreeNode* root, int low, int high) {
      if (root == NULL)
         return 0;
      if (root->val >= low && root->val <= high) {
         return root->val + rangeSumBST(root->left, low, high) +
               rangeSumBST(root->right, low, high);
      }
      if (root->val < low)
         return rangeSumBST(root->right, low, high);
      return rangeSumBST(root->left, low, high);
   }
};
```


## 🚀 Getting Started

1. Open the topic folder for the problem you solved.
2. Put the file in the matching difficulty folder.
3. Keep the file lightweight: link, concepts, short approach, TC/SC, and only the solution class.

## 📊 Progress Tracking

| Topic | Easy | Medium | Hard | Total |
|-------|------|--------|------|-------|
| Arrays | 4 | 4 | 0 | 8 |
| Backtracking | 0 | 0 | 0 | 0 |
| Bit_Magic | 0 | 0 | 0 | 0 |
| Design | 0 | 0 | 0 | 0 |
| DP | 0 | 0 | 1 | 1 |
| Graph | 0 | 0 | 0 | 0 |
| Greedy | 0 | 1 | 0 | 1 |
| HashMap | 0 | 0 | 0 | 0 |
| HashSet | 0 | 0 | 0 | 0 |
| Heap | 0 | 0 | 0 | 0 |
| Line Sweep Technique | 0 | 0 | 0 | 0 |
| Linked List | 1 | 0 | 0 | 1 |
| Mathematical | 3 | 0 | 0 | 3 |
| Queue | 0 | 0 | 0 | 0 |
| Recursion | 0 | 0 | 0 | 0 |
| Segment Tree | 0 | 0 | 1 | 1 |
| Sliding Window | 0 | 0 | 0 | 0 |
| Stack | 0 | 0 | 0 | 0 |
| Strings | 2 | 0 | 0 | 2 |
| Tree | 4 | 2 | 0 | 6 |
| Trie | 0 | 2 | 0 | 2 |
| **Total** | **14** | **9** | **2** | **25** |

## 🛠️ Technologies Used

- **C++**

## 📚 Resources

- [LeetCode](https://leetcode.com)
- [CodeStoryWithMik](https://www.youtube.com/@codestorywithmik)

## 📝 License

This project is licensed under the MIT License - see the LICENSE file for details.

## 📌 Disclaimer

These solutions are provided for educational purposes. While solving problems on your own is encouraged, these solutions can serve as reference material for learning different approaches and techniques.

---


Happy Coding! 🚀
