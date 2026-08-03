// LeetCode: https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/
// Concepts: String, Simulation, Math

/*
Intuition:
Repeatedly transform string `s` in-place until its length `n` reduces to 2.
In each operation, replace character `s[i]` with `((s[i] - '0') + (s[i+1] - '0')) % 10 + '0'`.
Finally, return whether `s[0] == s[1]`.

T.C: O(N^2) where N is the length of string `s`.
S.C: O(1) auxiliary space (in-place modification).
*/

class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();

        while (n > 2) {

            for (int i = 0; i < n - 1; i++) {
                s[i] = (((s[i] - '0') + (s[i + 1] - '0')) % 10) + '0';
            }

            n--;
        }
        
        return s[0] == s[1];
    }
};
