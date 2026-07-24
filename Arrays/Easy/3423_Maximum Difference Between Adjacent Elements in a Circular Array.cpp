// LeetCode: https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/
// Concepts: Array, Circular Array, Simulation

/*
Intuition:
Given a circular array `nums`, we need to find the maximum absolute difference between any two adjacent elements.
Because the array is circular:
- Elements `nums[i]` and `nums[i+1]` are adjacent for `0 <= i < n - 1`.
- The last element `nums[n-1]` and the first element `nums[0]` are also adjacent.

Iterate through `i` from 0 to `n-1`. For `i == n - 1`, compare `abs(nums[i] - nums[0])`, otherwise `abs(nums[i] - nums[i+1])`.
Track the maximum difference seen.

T.C: O(N)
S.C: O(1)
*/

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int maxDiff = INT_MIN;
        int diff = 0;

        for (int i = 0; i < n; i++) {
            if (i != n - 1) {
                diff = abs(nums[i] - nums[i + 1]);
            } else
                diff = abs(nums[i] - nums[0]);

            maxDiff = max(maxDiff, diff);
        }
        return maxDiff;
    }
};
