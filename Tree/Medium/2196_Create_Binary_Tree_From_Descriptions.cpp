// LeetCode: https://leetcode.com/problems/create-binary-tree-from-descriptions/
// Concepts: Tree, Hash Map

// Approach: Use a hash map to store all nodes and a set to track child nodes. Build tree connections from descriptions, then return the node that is never a child (the root).

// TC: O(n) | SC: O(n)

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        set<int> st;

        for (auto& vec : descriptions) {
            int parent = vec[0];
            int child = vec[1];
            st.insert(child);
            if (mp.find(parent) == mp.end()) {
                TreeNode* p = new TreeNode(parent);
                mp[p->val] = p;
            }
            if (mp.find(child) == mp.end()) {
                TreeNode* c = new TreeNode(child);
                mp[c->val] = c;
            }
            if (vec[2] == 1) {
                mp[parent]->left = mp[child];
            } else {
                mp[parent]->right = mp[child];
            }
        }

        for (auto vec : descriptions) {
            if (st.find(vec[0]) == st.end())
                return mp[vec[0]];
        }

        return mp[0];
    }
};
