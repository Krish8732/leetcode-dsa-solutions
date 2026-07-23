// Leetcode: https://leetcode.com/problems/reverse-bits/
// Concepts: Bit Manipulation

/*
Approach 1: Bit Inspection & Placement
For each bit position i from 0 to 31, extract the bit at position i from n.
If the bit is set (1), set the corresponding reversed position (31 - i) in the result.

T.C: O(1) - Always 32 iterations
S.C: O(1)
*/

class Solution {
public:
    int reverseBits(int n) {
        int result = 0;
        
        for (int i = 0; i < 32; i++) {
            int bit = n & (1 << i);
            if (bit) {
                result = result | (1 << (31 - i));
            }
        }

        return result;
    }
};

/*
Approach 2: Bit Shifting & Accumulation (Optimal)
Iterate 32 times. In each step, shift the result left by 1 to make space for the next bit,
take the lowest bit of n (n & 1), append it to result, and shift n right by 1.

T.C: O(1) - Always 32 iterations
S.C: O(1)
*/

class Solution {
public:
    int reverseBits(int n) {
        if (n == 0)
            return 0;

        int result = 0;
        for (int i = 0; i < 32; i++) {
            result = result << 1;
            result = result | (n & 1);
            n = n >> 1;
        }
        return result;
    }
};
