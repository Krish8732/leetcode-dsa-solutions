// LeetCode: https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/
// Concepts: Array, Simulation, Greedy

/*
Intuition:
While the array `nums` is not sorted (not non-decreasing) and has length > 1:
1. Find the adjacent pair `(nums[i], nums[i+1])` that has the minimum sum. If there are ties, choose the leftmost pair.
2. Replace `nums[i]` with the pair sum, and erase `nums[i+1]`.
3. Increment the operation counter `cnt`.

Repeat until `is_sorted(nums.begin(), nums.end())` holds true.

T.C: O(N^2) where N is length of nums (each step reduces array size by 1).
S.C: O(1) auxiliary space (in-place vector mutation).
*/

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int cnt = 0;

        while (nums.size() > 1 && !is_sorted(begin(nums), end(nums))) {
            int minSum = INT_MAX;
            int minIndex = INT_MAX;
            for (int i = 0; i < nums.size() - 1; i++) {
                int currSum = nums[i] + nums[i + 1];
                if (currSum < minSum) {
                    minSum = currSum;
                    minIndex = i;
                }
            }
            nums[minIndex] = minSum;

            nums.erase(nums.begin() + minIndex + 1);

            cnt++;
        }

        return cnt;
    }
};
