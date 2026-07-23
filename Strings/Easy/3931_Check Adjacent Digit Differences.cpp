// Leetcode: https://leetcode.com/problems/check-adjacent-digit-differences/
// Concepts: String, Simulation

/*
Intuition:
Iterate through the string s from index 0 to n - 2.
For each adjacent pair of digits at indices i and i + 1:
- Convert both characters to their integer digit values.
- Calculate the absolute difference: abs(firstDigit - secDigit).
- If the difference is greater than 2, return false immediately.
If all adjacent pairs have difference at most 2, return true.

T.C: O(n)
S.C: O(1)
*/

class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int n = s.size();
        for (int i = 0; i < n-1; i++){
            int firstDigit = s[i] - '0';
            int secDigit = s[i+1] - '0';
            int diff = abs(firstDigit - secDigit);
            if (diff > 2) return false;
        }

        return true;
    }
};
