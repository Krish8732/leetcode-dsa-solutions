// LeetCode: https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-i/
// Concepts: Array

/*
Intuition:
Count the elements in `nums` that are strictly less than `k` since each operation can remove one such element.

T.C: O(N)
S.C: O(1)
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int cnt = 0;
        for (int x : nums) {
            if (x < k) cnt++;
        }
        return cnt;
    }
};
