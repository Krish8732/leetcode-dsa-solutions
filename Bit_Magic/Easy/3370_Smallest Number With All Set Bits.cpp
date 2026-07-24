// LeetCode: https://leetcode.com/problems/smallest-number-with-all-set-bits/
// Concepts: Bit Manipulation, Math

/*
Intuition:
We need to find the smallest number `x >= n` such that the binary representation of `x` consists entirely of set bits (1s).
Numbers with all set bits are of the form `2^k - 1` (e.g. 1, 3, 7, 15, 31, ...).

1. Calculate the number of bits needed to represent `n`: `bits = log2(n) + 1`.
2. Construct the all-ones value as `(1 << bits) - 1`.

T.C: O(1) using math `log2`
S.C: O(1)
*/

class Solution {
public:
    int smallestNumber(int n) {
        int bits = log2(n) + 1;

        return ( 1 << bits ) - 1;
    }
};
