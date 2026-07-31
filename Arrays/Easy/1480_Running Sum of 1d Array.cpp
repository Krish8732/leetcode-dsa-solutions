// LeetCode: https://leetcode.com/problems/running-sum-of-1d-array/
// Concepts: Array, Prefix Sum

/*
Intuition:
The running sum at index `i` is the sum of all elements from index `0` to `i`.
Instead of recalculating the sum from the beginning for each index, we can accumulate the sum in a variable as we iterate through the array and update `nums[i]` directly in-place.

T.C: O(N) where N is the number of elements in nums.
S.C: O(1) auxiliary space (modifying the input array in-place).
*/

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum = 0;
        for ( int i = 0; i<nums.size(); i++){
             sum += nums[i];
             nums[i] = sum;
        }
        return nums;
    }
};
