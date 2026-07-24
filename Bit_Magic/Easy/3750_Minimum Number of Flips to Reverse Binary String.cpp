// LeetCode: https://leetcode.com/problems/minimum-number-of-flips-to-reverse-binary-string/
// Concepts: Bit Manipulation, String, Two Pointers

/*
Intuition:
We are given a positive integer `n`. We consider its binary representation without leading zeros and want to find the minimum flips to make it a binary palindrome.
When a bit pair at symmetric positions from start and end `(s[i]` and `s[n-1-i])` does not match, flipping one bit changes the string, but to maintain/reach a palindrome symmetry with flip operations where both bits mismatch, each mismatched pair adds 2 flips.

Approach 1 (String Conversion):
- Convert `n` to a 32-bit binary string using `bitset<32>(n).to_string()`.
- Trim leading zeros using `substr(s.find('1'))`.
- Compare symmetric character pairs `s[i]` and `s[s.size() - 1 - i]` up to `s.size() / 2`.
- Increment flip count by 2 for each mismatch.
T.C: O(32) = O(1)
S.C: O(32) = O(1)

Approach 2 (Bitwise Two Pointers - Space Optimized):
- Find the most significant bit (MSB) position `left` by checking `(n >> left) & 1`.
- Initialize `right = 0` (least significant bit position).
- Move `left` inward towards `right`, extracting bit values at `left` and `right`.
- If `b1 != b2`, increment flip count by 2.
T.C: O(log2(n)) = O(1)
S.C: O(1)
*/

// Approach 1: String Conversion using bitset
class Solution {
public:
    int minimumFlips(int n) {
        string s = bitset<32>(n).to_string();
        s = s.substr(s.find('1'));
        int cnt = 0;

        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - i - 1]) cnt += 2;
        }

        return cnt;
    }
};

// Approach 2: Direct Bit Manipulation without extra space
class SolutionBitwise {
public:
    int minimumFlips(int n) {
        int left = 31;
        while (left >= 0 && ((n >> left) & 1) == 0)
            left--;

        int right = 0;
        int cnt = 0;

        while (left > right) {
            int b1 = (n >> left) & 1;
            int b2 = (n >> right) & 1;

            if (b1 != b2)
                cnt += 2;

            left--;
            right++;
        }

        return cnt;
    }
};
