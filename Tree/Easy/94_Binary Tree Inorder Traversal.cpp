// LeetCode: https://leetcode.com/problems/binary-tree-inorder-traversal/
// Concepts: Tree, DFS, Inorder Traversal

// Approach: Traverse the tree recursively in left-root-right order and collect node values.

// TC: O(n) | SC: O(h)

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;

        inorder(root->left, result);     
        result.push_back(root->val);    
        inorder(root->right, result); 
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
};