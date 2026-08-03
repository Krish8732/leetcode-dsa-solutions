// LeetCode: https://leetcode.com/problems/minimum-absolute-difference/
// Concepts: Array, Sorting

/*
Intuition:
1. Sort the input array `arr` in ascending order.
2. Iterate through adjacent elements to find the overall minimum absolute difference `minDiff`.
3. In a second pass, collect all adjacent pairs `(arr[i], arr[i+1])` whose difference equals `minDiff`.

T.C: O(N log N) due to sorting.
S.C: O(1) auxiliary space (excluding result array).
*/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();

        sort(arr.begin(), arr.end());

        int minDiff = INT_MAX;

        for (int i = 0; i < n - 1; i++) {
            int left = arr[i];
            int right = arr[i + 1];
            int diff = right - left;
            minDiff = min(minDiff, diff);
        }

        vector<vector<int>> result;

        for (int i = 0; i < n - 1; i++) {
            if (arr[i + 1] - arr[i] == minDiff) {
                result.push_back({arr[i], arr[i + 1]});
            }
        }

        return result;
    }
};
