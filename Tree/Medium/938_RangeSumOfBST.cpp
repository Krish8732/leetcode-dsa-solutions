// LeetCode: https://leetcode.com/problems/range-sum-of-bst/
// Concepts: DFS, BST pruning

// Approach: Traverse only the branches that can still contain valid values.

// TC: O(n) | SC: O(1) ignoring recursion stack space
 
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == NULL)
            return 0;
        if (root->val >= low && root->val <= high) {
            return root->val + rangeSumBST(root->left, low, high) +
                   rangeSumBST(root->right, low, high);
        }
        if (root->val < low) {
            return rangeSumBST(root->right, low, high);
        }
        return rangeSumBST(root->left, low, high);
    }
};