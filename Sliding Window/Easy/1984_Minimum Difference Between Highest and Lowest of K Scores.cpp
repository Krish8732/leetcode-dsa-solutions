// LeetCode: https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/
// Concepts: Array, Sliding Window, Sorting

/*
Intuition:
To minimize the difference between the highest and lowest of any k scores chosen, sort the array first.
After sorting, any contiguous subarray of size `k` represents a selection of `k` elements where the minimum is `nums[i]` and maximum is `nums[i + k - 1]`.
Use a sliding window of size `k` to compute `nums[i + k - 1] - nums[i]` and track the global minimum difference.

T.C: O(N log N) due to sorting.
S.C: O(1) auxiliary space.
*/

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int minDiff = INT_MAX;

        int i = 0;
        int j = k-1;

        while(j < n){
            int minEl = nums[i];
            int maxEl = nums[j];
            minDiff = min(minDiff, maxEl-minEl);

            i++, j++;
        }

        return minDiff;
    }
};
