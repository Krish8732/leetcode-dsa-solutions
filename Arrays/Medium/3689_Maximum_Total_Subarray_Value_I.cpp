// LeetCode: https://leetcode.com/problems/maximum-total-subarray-value-i/
// Concepts: Array, Greedy

// Approach: The maximum value of any subarray is bounded by (max(nums) - min(nums)). Since we can choose the same subarray multiple times, the optimal strategy is to repeatedly choose the subarray containing both the global maximum and the global minimum. Thus, the maximum total value is (max(nums) - min(nums)) * k.

// TC: O(n) | SC: O(1)

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxi = nums[0];
        int mini = nums[0];
        for (int x : nums) {
            maxi = max(maxi, x);
            mini = min(mini, x);
        }

        return (long long)(maxi - mini) * k;
    }
};
