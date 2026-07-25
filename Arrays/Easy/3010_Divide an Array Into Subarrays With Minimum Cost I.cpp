// LeetCode: https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/
// Concepts: Array, Sorting, Greedy

/*
Intuition:
We need to divide `nums` into 3 contiguous subarrays. The cost of a subarray is its first element.
- The first subarray must start at `nums[0]`, so `nums[0]` is always included.
- The second and third subarrays can start at any indices `i` and `j` where `1 <= i < j < n`.
- To minimize the total cost, we select `nums[0]` plus the two smallest elements in `nums[1...n-1]`.

1. Set `num1 = nums[0]`.
2. Find the two smallest values `num2` and `num3` in `nums[1...n-1]`.
3. Return `num1 + num2 + num3`.

T.C: O(N) where N is the length of `nums`.
S.C: O(1) auxiliary space.
*/

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int num1 = nums[0], num2 = INT_MAX, num3 = INT_MAX;
        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] < num2) {
                num3 = num2;
                num2 = nums[i];
            } else if (nums[i] < num3) {
                num3 = nums[i];
            }
        }
        return num1 + num2 + num3;
    }
};
