// LeetCode: https://leetcode.com/problems/same-tree/
// Concepts: Tree, DFS, Recursion

// Approach: Recursively compare both trees node by node. The trees match only when both current nodes are null, or both are non-null with the same value and matching left and right subtrees.

// TC: O(n) | SC: O(h)

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;  // Both are null
        if (!p || !q) return false; // One is null

        if (p->val != q->val) return false;

        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};