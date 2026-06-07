//recursive soln

// Approach 1 (Recursive): Postorder traversal - visit left subtree, right subtree, then node.

// TC: O(n) | SC: O(h) where h is the height of the tree (call stack)

class Solution {
public:
    void postOrder(TreeNode* root, vector<int>& result){
        if (!root) return;

        postOrder(root->left, result);
        postOrder(root->right, result);
        result.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        postOrder(root, result);
        return result;
    }
};

// Approach 2 (Iterative - Two Stacks): Use two stacks to simulate postorder traversal by reversing preorder.

// TC: O(n) | SC: O(n)

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        
        stack<TreeNode*> st1, st2;
        vector<int> result;
        
        st1.push(root);
        while (!st1.empty()) {
            TreeNode* curr = st1.top();
            st1.pop();
            st2.push(curr);
            
            if (curr->left) st1.push(curr->left);
            if (curr->right) st1.push(curr->right);
        }
        
        while (!st2.empty()) {
            result.push_back(st2.top()->val);
            st2.pop();
        }
        
        return result;
    }
};
