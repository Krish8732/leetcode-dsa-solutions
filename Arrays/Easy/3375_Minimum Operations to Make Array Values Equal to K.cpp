// LeetCode: https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/
// Concepts: Array, Hash Table, Greedy

/*
Intuition:
We want to make all elements in `nums` equal to `k` using the minimum number of operations where an operation sets all values > h to h.

1. If any element `x < k`, it is impossible to make all elements equal to `k` since we can only reduce values. Return `-1`.
2. Find the minimum element `mi` in `nums` and insert all elements into an `unordered_set<int> s` to track unique values.
3. The number of operations required equals the count of unique values (`s.size()`), minus 1 if `k` is already present in the array (`mi == k` or `k in s`).

T.C: O(N)
S.C: O(N)
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> s;
        int mi = INT_MAX;
        for (int x : nums) {
            if (x < k) {
                return -1;
            }
            mi = min(mi, x);
            s.insert(x);
        }
        return s.size() - (mi == k);
    }
};
