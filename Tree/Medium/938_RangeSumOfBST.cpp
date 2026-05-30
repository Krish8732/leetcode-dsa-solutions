/**
 * Problem: Range Sum of BST
 * LeetCode #: 938
 * Difficulty: Medium
 * Topics: Tree, Binary Search Tree, DFS
 * 
 * Problem Description:
 * Given the root node of a binary search tree and two integers low and high, 
 * return the sum of values of all nodes with a value in the inclusive range [low, high].
 * 
 * Approach:
 * - Use DFS (Depth-First Search) to traverse the BST
 * - Since it's a BST, we can optimize:
 *   - If node->val < low: only explore right subtree (left subtree will also be < low)
 *   - If node->val > high: only explore left subtree (right subtree will also be > high)
 *   - If node->val is in range [low, high]: include it in sum and explore both subtrees
 * 
 * Time Complexity: O(n) worst case, but typically O(h + k) where h=height, k=nodes in range
 * Space Complexity: O(h) for recursion stack
 * 
 * Example:
 * Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
 * Output: 32
 * Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. Sum = 7 + 10 + 15 = 32
 */

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        // Base case
        if (!root) {
            return 0;
        }
        
        // If current node value is less than low, go right
        if (root->val < low) {
            return rangeSumBST(root->right, low, high);
        }
        
        // If current node value is greater than high, go left
        if (root->val > high) {
            return rangeSumBST(root->left, low, high);
        }
        
        // Current node is in range [low, high]
        // Include it and explore both subtrees
        return root->val + 
               rangeSumBST(root->left, low, high) + 
               rangeSumBST(root->right, low, high);
    }
};

// Alternative iterative approach using queue
class SolutionIterative {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (!node) continue;
            
            // If in range, include in sum
            if (node->val >= low && node->val <= high) {
                sum += node->val;
                q.push(node->left);
                q.push(node->right);
            }
            // If value is less than low, explore right
            else if (node->val < low) {
                q.push(node->right);
            }
            // If value is greater than high, explore left
            else {
                q.push(node->left);
            }
        }
        
        return sum;
    }
};
