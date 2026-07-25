// LeetCode: https://leetcode.com/problems/smallest-even-multiple/
// Concepts: Math

/*
Intuition:
Given a positive integer `n`, return the smallest positive integer that is a multiple of both 2 and `n`.

Approach 1: Simulation
While `n % 2 != 0`, add `n` to itself (`n += n`).
T.C: O(1)
S.C: O(1)

Approach 2: Optimal O(1) Check
If `n` is already even, the smallest multiple of both 2 and `n` is `n`.
If `n` is odd, the smallest multiple is `n * 2`.
T.C: O(1)
S.C: O(1)
*/

// Approach 1: Simulation
class SolutionSimulation {
public:
    int smallestEvenMultiple(int n) {
        while (n % 2 != 0) {
            n += n;
        }
        return n;
    }
};

// Approach 2: Optimal O(1)
class Solution {
public:
    int smallestEvenMultiple(int n) {
        return (n % 2 == 0) ? n : n * 2;
    }
};
