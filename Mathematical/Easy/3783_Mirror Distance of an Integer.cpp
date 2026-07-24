// LeetCode: https://leetcode.com/problems/mirror-distance-of-an-integer/
// Concepts: Math

/*
Intuition:
The mirror distance of an integer `n` is defined as the absolute difference between `n` and its reversed digit representation.

1. Reverse the digits of `n` using standard digit manipulation (`rev = rev * 10 + temp % 10`).
2. Return `abs(n - rev)`.

T.C: O(log10(n))
S.C: O(1)
*/

class Solution {
public:
    int mirrorDistance(int n) {
        int temp = n;
        int rev = 0;
        while (temp > 0) {
            rev = rev * 10 + temp % 10;
            temp = temp / 10;
        }

        return abs(n - rev);
    }
};
