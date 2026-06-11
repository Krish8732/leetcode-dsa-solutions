// LeetCode: https://leetcode.com/problems/balanced-binary-tree/
// Concepts: Tree, DFS, Recursion

// Approach 1 (Naive Recursion): We check the height of the left and right subtrees at each node using a helper height function. We verify if the current node is balanced by ensuring the absolute height difference is at most 1, then recursively check the left and right subtrees.
// TC: O(n^2) | SC: O(h)

class Solution {
public:
    int height(TreeNode* root){
        if (!root) return 0;
        int leftH = height(root->left);
        int rightH = height(root->right);
        return 1 + max(leftH, rightH);
    }
   
    bool check(TreeNode* root){

        if (!root) return true;
        int leftH = height(root->left);
        int rightH = height(root->right);
        if (abs(leftH-rightH) > 1 ) return false;

        return (check(root->left) && check(root->right));

    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        return check(root);
    }
};

// Approach 2 (Optimal O(n) DFS): Instead of recalculating height repeatedly, we check balance status and height in a single DFS traversal. The function returns the height if the subtree is balanced, or -1 if any subtree is unbalanced, propagating the failure up immediately.
// TC: O(n) | SC: O(h)

class Solution {
public:
    int dfs(TreeNode* root) {
        if (!root)
            return 0;
        int leftH = dfs(root->left);
        if (leftH == -1)
            return -1;
        int rightH = dfs(root->right);
        if (rightH == -1)
            return -1;
        if (abs(leftH - rightH) > 1)
            return -1;
        return 1 + max(leftH, rightH);
    }

    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        return (dfs(root) != -1);
    }
};
