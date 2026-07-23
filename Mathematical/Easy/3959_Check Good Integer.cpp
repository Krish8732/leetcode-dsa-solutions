// Leetcode: https://leetcode.com/problems/check-good-integer/
// Concepts: Math, String, Simulation

/*
Intuition:
Convert the integer n to a string s.
Iterate over each digit character c in s:
- Compute digitSum (ds) by adding (c - '0').
- Compute squareSum (ss) by adding (c - '0') * (c - '0').
Return true if (ss - ds >= 50), otherwise return false.

T.C: O(log n) - Number of digits in n
S.C: O(log n) for string conversion
*/

class Solution {
public:
    bool checkGoodInteger(int n) {
        string s = to_string(n);

        long long ds = 0;
        long long ss = 0;

        for (char c : s) {
            ds += c - '0';
            ss += (c - '0') * (c - '0');
        }

        return (ss - ds >= 50);
    }
};
