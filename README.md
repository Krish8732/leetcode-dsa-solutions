# LeetCode DSA Solutions

[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=black)](https://leetcode.com/u/Krish1199/)
[![Problems Solved](https://img.shields.io/badge/Problems%20Solved-195-brightgreen?style=for-the-badge&logo=leetcode)](https://leetcode.com/u/Krish1199/)

<p align="center">
  <img src="https://leetcard.jacoblin.cool/Krish1199?theme=dark&font=Inter" alt="LeetCode Stats Card" />
</p>

This repository is a clean collection of LeetCode solutions organized by topic and difficulty. Each file is meant to stay close to the code you submit on LeetCode: minimal notes, minimal clutter.

## 📁 Repository Structure

Solutions are organized by **21 major DSA topics**, each containing problems categorized by **difficulty levels** (Easy, Medium, Hard):

```
leetcode-dsa-solutions/
├── Arrays/
├── Backtracking/
├── Bit_Magic/
├── DP/
├── Design/
├── Graph/
├── Greedy/
├── HashMap/
├── HashSet/
├── Heap/
├── Line Sweep Technique/
├── Linked List/
├── Mathematical/
├── Queue/
├── Recursion/
├── Segment Tree/
├── Sliding Window/
├── Stack/
├── Strings/
├── Tree/
└── Trie/
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
| [Arrays](./Arrays) | 60 | 9 | 0 | 69 |
| [Backtracking](./Backtracking) | 0 | 0 | 0 | 0 |
| [Bit_Magic](./Bit_Magic) | 6 | 2 | 0 | 8 |
| [Design](./Design) | 0 | 0 | 0 | 0 |
| [DP](./DP) | 0 | 2 | 3 | 5 |
| [Graph](./Graph) | 0 | 1 | 0 | 1 |
| [Greedy](./Greedy) | 4 | 4 | 0 | 8 |
| [HashMap](./HashMap) | 1 | 0 | 0 | 1 |
| [HashSet](./HashSet) | 6 | 0 | 0 | 6 |
| [Heap](./Heap) | 0 | 0 | 0 | 0 |
| [Line Sweep Technique](./Line%20Sweep%20Technique) | 0 | 0 | 0 | 0 |
| [Linked List](./Linked%20List) | 3 | 2 | 0 | 5 |
| [Mathematical](./Mathematical) | 33 | 5 | 0 | 38 |
| [Queue](./Queue) | 0 | 0 | 0 | 0 |
| [Recursion](./Recursion) | 0 | 0 | 0 | 0 |
| [Segment Tree](./Segment%20Tree) | 0 | 0 | 1 | 1 |
| [Sliding Window](./Sliding%20Window) | 1 | 0 | 1 | 2 |
| [Stack](./Stack) | 1 | 0 | 0 | 1 |
| [Strings](./Strings) | 35 | 3 | 0 | 38 |
| [Tree](./Tree) | 8 | 2 | 0 | 10 |
| [Trie](./Trie) | 0 | 2 | 0 | 2 |
| **Total** | **158** | **32** | **5** | **195** |

## 🛠️ Technologies Used

- **C++**

## 📚 Resources

- [LeetCode](https://leetcode.com)
- [GeeksforGeeks](https://www.geeksforgeeks.org/)
- [Competitive Programmer's Handbook (Antti Laaksonen)](https://cses.fi/book/book.pdf)
- [take U forward / Striver](https://www.youtube.com/@takeUforward)
- [Colin Galen](https://www.youtube.com/@ColinGalen)
- [CodeStoryWithMik](https://www.youtube.com/@codestorywithmik)

## 📝 License

This project is licensed under the MIT License - see the LICENSE file for details.

## 📌 Disclaimer

These solutions are provided for educational purposes. While solving problems on your own is encouraged, these solutions can serve as reference material for learning different approaches and techniques.

---

Happy Coding! 🚀
