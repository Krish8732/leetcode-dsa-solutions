// LeetCode: https://leetcode.com/problems/rank-transform-of-an-array/
// Concepts: Array, Hash Table, Sorting

/*
Approach: Use a sorted map to store each unique value in the array mapped to all the indices where it appears.
Since map keeps keys sorted in ascending order, we can iterate through the map and assign ranks sequentially.
TC: O(n log n) - Insertion of elements into the map.
SC: O(n) - Storage for the map and vectors of indices.
*/

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, vector<int>> mp;

        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]].push_back(i);
        }

        int rankLimit = mp.size();

        int currRank = 1;

        for (auto& it : mp) {
            int val = it.first;
            vector<int> idxs = it.second;

            for (int idx : idxs) {
                arr[idx] = currRank;
            }
            currRank++;
        }

        return arr;
    }
};
