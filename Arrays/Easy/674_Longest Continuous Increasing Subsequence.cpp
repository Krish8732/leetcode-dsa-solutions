// LeetCode: https://leetcode.com/problems/longest-continuous-increasing-subsequence/
// Concepts: Array

/*
Intuition:
Iterate through the array and compare adjacent elements (`nums[i+1]` and `nums[i]`).
- If `nums[i+1] > nums[i]`, increment current sequence length.
- Otherwise, reset sequence length to 1.
Keep track of the maximum length encountered.

T.C: O(N)
S.C: O(1)
*/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 1;
        int length = 1;
        for ( int i = 0; i < n-1; i++ ){
            if (nums[i+1] > nums[i]){
                length++;
            }
            else length = 1;

            maxLength = max(maxLength, length);
        }
        return maxLength;
    }
};
