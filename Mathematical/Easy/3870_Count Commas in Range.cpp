// LeetCode: https://leetcode.com/problems/count-commas-in-range/
// Concepts: Math

/*
Approach:
For n <= 10^5, commas only appear in numbers >= 1000, and each such number contains exactly one comma. 
Thus, the total number of commas is n - 999 for n >= 1000, and 0 for n < 1000.

TC: O(1) - Constant time arithmetic check and subtraction.
SC: O(1) - Constant auxiliary space.
*/

class Solution {
public:
    int countCommas(int n) {
        if (n < 1000) return 0;
        return n - 999;
    }
};
