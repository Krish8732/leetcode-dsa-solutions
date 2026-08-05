// LeetCode: https://leetcode.com/problems/remove-methods-from-project/
// Concepts: Graph, Depth-First Search

/*
Approach:
Intuition:
As we need to find all infected either we can do that in one dfs or bfs traversal and marking them visited, then check for all other unaffected nodes if 0 return empty else either you can dfs call from every one of them and marking them visited but that would become messy to maintain two visited arrays and validating them, so we can simply iterate through given 2d vector for a to b node and check if the unaffected component is connected to affected one via any two nodes , or same can be done via adj.

TC: O(n + m) - where n is the number of methods and m is the number of invocations.
SC: O(n + m) - to store the adjacency list representation of the graph and the visited state.
*/

class Solution {
public:
    void dfs(int node, vector<bool>& susNodes,
             unordered_map<int, vector<int>>& adj) {
        if (susNodes[node]) {
            return;
        }

        susNodes[node] = true;

        for (int& ngbr : adj[node]) {
            if (susNodes[ngbr])
                continue;
            dfs(ngbr, susNodes, adj);
        }

        return;
    }

    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        unordered_map<int, vector<int>> adj;
        vector<bool> susNodes(n, 0);

        for (auto& vec : invocations) {
            int a = vec[0];
            int b = vec[1];
            adj[a].push_back(b);
        }

        dfs(k, susNodes, adj);
        int notSus = -1;

        for (int i = 0; i < n; i++) {
            if (!susNodes[i]) {
                notSus = i;
                break;
            }
        }

        if (notSus == -1)
            return {};

        bool connected = false;
        vector<int> result;

        for (auto& vec : invocations) {
            int a = vec[0];
            int b = vec[1];
            if (!susNodes[a] && susNodes[b]) {
                connected = true;
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (!connected && susNodes[i]) {
                continue;
            }
            result.push_back(i);
        }

        return result;
    }
};
