// LeetCode: https://leetcode.com/problems/concatenation-of-array/
// Concepts: Array, Simulation

/*
Intuition:
We need to return `ans` of length `2*n` where:
- The first half `ans[0 ... n-1]` is identical to `nums`.
- The second half `ans[n ... 2n-1]` is also identical to `nums`.

Simply iterate over `nums` once and assign each element to both its original index `i`
and the shifted index `i + n` in the result array.

T.C: O(N) where N is the size of `nums`.
S.C: O(N) for the output array `ans` of size 2*N.
*/

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2*n);
        for ( int i = 0; i<n; i++){
            ans[i] = nums[i];
            ans[i + n] = nums[i];
        }
        return ans;
    }
};
