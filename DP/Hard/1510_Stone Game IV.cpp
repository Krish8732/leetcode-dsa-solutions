// LeetCode: https://leetcode.com/problems/stone-game-iv/
// Concepts: Dynamic Programming, Math, Game Theory

/*
Intuition:
Alice and Bob take turns removing a non-zero square number of stones from n. The player who cannot make a move loses.

Approach:
1. Top-Down Recursion with Memoization:
   For a given `n`, try subtracting every square number `i * i <= n`.
   If any resulting state `n - (i * i)` returns `false` (meaning the next player loses), then the current player can win from state `n` (`true`).
   If all possible moves lead to winning states for the next player, the current player loses (`false`).

T.C: O(N * sqrt(N))
S.C: O(N) auxiliary space for memoization array and recursion call stack.
*/

class Solution {
public:
    vector<int> dp;

    int solve(int n) {

        if (n == 0)
            return false;

        if (dp[n] != -1)
            return dp[n];

        for (int i = 1; i * i <= n; i++) {
            if (!solve(n - (i * i)))
                return dp[n] = true;
        }

        return dp[n] = false;
    }

    bool winnerSquareGame(int n) {
        dp.resize(n + 1, -1);
        return solve(n);
    }
};
