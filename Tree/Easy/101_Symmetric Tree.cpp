// LeetCode: https://leetcode.com/problems/symmetric-tree/
// Concepts: Tree, DFS, Recursion
// Approach: Check root's left and right values, then recursively check left and right of left and right subtrees.
// TC: O(n) | SC: O(h)

class Solution {
public:
    bool check(TreeNode* l, TreeNode* r) {
        if (!l && !r)
            return true;
        if (!l || !r)
            return false;
        return (l->val == r->val) && check(l->left, r->right) &&
               check(l->right, r->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return check(root->left, root->right);
    }
};
