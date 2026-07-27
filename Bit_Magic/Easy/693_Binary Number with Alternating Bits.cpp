// LeetCode: https://leetcode.com/problems/binary-number-with-alternating-bits/
// Concepts: Bit Manipulation

/*
Intuition:
Extract the least significant bit `prevBit = n & 1` and right shift `n` by 1.
Loop while `n > 0`, checking the current bit `currBit = n & 1`.
- If `prevBit == currBit`, adjacent bits are identical, return `false`.
- Otherwise, update `prevBit = currBit` and right shift `n >> 1`.
If loop finishes without finding adjacent matching bits, return `true`.

T.C: O(log N)
S.C: O(1)
*/

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prevBit = n & 1;
        n = n >> 1;
        while (n > 0) {
            int currBit = n & 1;
            if (prevBit == currBit)
                return false;
            prevBit = currBit;
            n = n >> 1;
        }

        return true;
    }
};
