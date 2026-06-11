// LeetCode: https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Concepts: Tree, DFS, Binary Tree
// Approach: Recursively find the maximum depth of the left and right subtrees, then return 1 + the maximum of the two.
// TC: O(n) | SC: O(h)

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return 1 + max(leftDepth, rightDepth);
    }
};
