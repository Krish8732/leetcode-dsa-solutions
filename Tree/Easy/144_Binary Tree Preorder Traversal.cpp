// LeetCode: https://leetcode.com/problems/binary-tree-preorder-traversal/
// Concepts: Tree, Recursion, DFS

// Approach: Recursive preorder traversal - visit node, then left subtree, then right subtree.

// TC: O(n) | SC: O(h) where h is the height of the tree (call stack)

class Solution {
public:
    void preOrder(TreeNode* node, vector<int>& result) {
        if (!node)
            return;

        result.push_back(node->val);
        preOrder(node->left, result);
        preOrder(node->right, result);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        preOrder(root, result);
        return result;
    }
};

// Approach 2 (Iterative): Use an explicit stack to simulate the recursion.

// TC: O(n) | SC: O(h)

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;

        if (!root)
            return result;

        stack<TreeNode*> st;

        st.push(root);
        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();
            result.push_back(curr->val);
            if (curr->right)
                st.push(curr->right);
            if (curr->left)
                st.push(curr->left);
        }

        return result;
    }
};