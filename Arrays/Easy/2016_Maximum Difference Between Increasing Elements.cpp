// LeetCode: https://leetcode.com/problems/maximum-difference-between-increasing-elements/
// Concepts: Array, Prefix Minimum

/*
Intuition:
To maximize `nums[j] - nums[i]` with `i < j`, we want to keep track of the minimum element seen so far (`mini`) to the left of index `j`.
As we iterate from left to right:
- If `nums[i] > mini`, we calculate `nums[i] - mini` and update `maxDiff`.
- Otherwise, if `nums[i] <= mini`, we update `mini` because a smaller element encountered later will yield a larger difference for future elements.

T.C: O(N) single pass where N is the size of nums.
S.C: O(1) auxiliary space.
*/

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
      int mini = nums[0];
      int maxDiff = -1;
      for(int i = 1; i<nums.size(); i++){
        if (nums[i] > mini){
         maxDiff = max(maxDiff, nums[i] - mini);
        }
        else{
            mini = min(mini, nums[i]);
        }
      }
      return maxDiff;
    }
};
