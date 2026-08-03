// LeetCode: https://leetcode.com/problems/count-good-triplets/
// Concepts: Array, Enumeration

/*
Intuition:
Brute force three nested loops over indices (0 <= i < j < k < n).
For each triplet (i, j, k), check if all three conditions are satisfied:
1. `abs(arr[i] - arr[j]) <= a`
2. `abs(arr[j] - arr[k]) <= b`
3. `abs(arr[i] - arr[k]) <= c`

Note on Optimization (Early Pruning):
We can optimize by early pruning: if `abs(arr[i] - arr[j]) > a`, we can skip the inner `k` loop immediately.
However, worst-case time complexity remains O(N^3).

T.C: O(N^3)
S.C: O(1) auxiliary space.
*/

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    ans += abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c;
                }
            }
        }
        return ans;
    }
};
