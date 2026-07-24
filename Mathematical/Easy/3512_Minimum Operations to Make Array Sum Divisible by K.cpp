// LeetCode: https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/
// Concepts: Math, Array

/*
Intuition:
Each decrement operation on any element decreases the total sum of `nums` by 1.
To make the sum divisible by `k`, the minimum number of operations required is equal to the remainder of the total sum when divided by `k` (`sum % k`).

T.C: O(N)
S.C: O(1)
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long sum = 0;
        for (int x : nums) sum += x;
        return sum % k;
    }
};
