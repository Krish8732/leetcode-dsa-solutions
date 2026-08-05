// LeetCode: https://leetcode.com/problems/binary-prefix-divisible-by-5/
// Concepts: Array, Bit Manipulation, Math

/*
Approach:
Intuition:
To avoid integer overflow when constructing the binary number from the array, we can perform all arithmetic operations modulo 5. As we traverse the array and shift the binary number to the left (multiplying the current value by 2 and adding the new bit), we only need to maintain the remainder modulo 5. If at any step the remainder is 0, the prefix is divisible by 5.

TC: O(n) - Single pass through the array of size n.
SC: O(1) - Auxiliary space complexity (excluding result array).
*/

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> result(n);
        int remain = 0;

        for (int i = 0; i<n; i++){
            remain = (remain*2 + nums[i]) % 5;

            result [i] = (remain == 0);
        }
        return result;
    }
};
