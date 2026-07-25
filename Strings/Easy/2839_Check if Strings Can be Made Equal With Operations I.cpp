// LeetCode: https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/
// Concepts: String, Enumeration

/*
Intuition:
We are given two strings `s1` and `s2` of length 4.
We can swap characters at indices `i` and `j` if `j - i = 2`.
This means:
- Even positions (indices 0 and 2) can be swapped with each other.
- Odd positions (indices 1 and 3) can be swapped with each other.

Check if even indices match and odd indices match.

T.C: O(1)
S.C: O(1)
*/

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        bool condition1 = (s1[0] == s2[0] && s1[2] == s2[2]) || (s1[0] == s2[2] && s1[2] == s2[0]);

        bool condition2 = (s1[1] == s2[1] && s1[3] == s2[3]) || (s1[1] == s2[3] && s1[3] == s2[1]);

        return condition1 && condition2;
    }
};
