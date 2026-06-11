// LeetCode: https://leetcode.com/problems/minimum-depth-of-binary-tree/
// Concepts: Tree, DFS, BFS, Queue, Recursion

// Approach 1 (DFS / Recursion): Recursively find the minimum depth from the root to a leaf node. If a node has only one child, we must traverse that active child's subtree. If it has both children, we take the minimum of their depths and add 1.
// TC: O(n) | SC: O(h)

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        if (!root->left){
            return 1 + minDepth(root->right);
        }
        if (!root->right){
            return 1 + minDepth(root->left);
        }

        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

// Approach 2 (BFS / Level Order Traversal): Perform a level-order traversal using a queue to find the shortest path to a leaf node. The first leaf node we encounter during the traversal yields the minimum depth, making it highly efficient for unbalanced trees.
// TC: O(n) | SC: O(n)

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        
        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();
            
            if (!node->left && !node->right)
                return depth;
            
            if (node->left) q.push({node->left, depth + 1});
            if (node->right) q.push({node->right, depth + 1});
        }
        
        return 0;
    }
};
