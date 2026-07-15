// LeetCode: https://leetcode.com/problems/path-existence-queries-in-a-graph-i/
// Concepts: Graph, Sorting, Union-Find / Connected Components

/*
Approach: 
Intuition:
1. Because the input array `nums` is sorted, two adjacent elements `nums[i]` and `nums[i-1]` have a direct edge between them if `nums[i] - nums[i-1] <= maxDiff`.
2. Connectivity is transitive: if `i` is connected to `i-1` and `i-1` to `i-2`, then all three are in the same connected component.
3. If `nums[i] - nums[i-1] > maxDiff`, there is a gap. Because the array is sorted, no element to the left of the gap (index < i) can connect to any element to the right of the gap (index >= i).
4. Therefore, the graph's connected components are simply contiguous segments of the array separated by these gaps.
5. We can assign component IDs in a single pass: start with component ID 0, and increment it whenever we find a gap where `nums[i] - nums[i-1] > maxDiff`.
6. For each query, `u` and `v` have a path if and only if they belong to the same component (`components[u] == components[v]`).

TC: O(n + q) - One pass to find components, and O(1) time per query.
SC: O(n) - To store the component ID for each node.
*/

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        vector<int> components(n, -1);
        int compId = 0;
        components[0] = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > maxDiff)
                compId++;
            components[i] = compId;
        }

        vector<bool> answer;

        for (auto& query : queries) {
            int u = query[0];
            int v = query[1];
            answer.push_back(components[u] == components[v]);
        }

        return answer;
    }
};
