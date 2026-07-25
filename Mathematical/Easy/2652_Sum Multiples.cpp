// LeetCode: https://leetcode.com/problems/sum-multiples/
// Concepts: Math, Enumeration

/*
Intuition:
Given a positive integer `n`, find the sum of all integers in the range [1, n] inclusive that are divisible by 3, 5, or 7.

Iterate through `i` from 3 to `n`. If `i` is divisible by 3, 5, or 7 (`i % 3 == 0 || i % 5 == 0 || i % 7 == 0`), add `i` to `sum`.

T.C: O(N)
S.C: O(1)
*/

class Solution {
public:
    int sumOfMultiples(int n) {
        int sum = 0;
        for (int i = 3; i <= n; i++) {
            if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0)
                sum += i;
        }
        return sum;
    }
};
