// LeetCode: https://leetcode.com/problems/stone-game/
// Concepts: Dynamic Programming, Recursion, Game Theory, Minimax, Math

// Approach 1: Minimax Recursion with Memoization (Absolute Score Maximization)
// - We calculate the maximum total stones Alex/Alice can gather.
// - Since the opponent plays optimally, they leave us with the minimum outcome for our next turn.
// - Time Complexity: O(N^2)
// - Space Complexity: O(N^2)

class Solution {
public:
    int dp[501][501];

    int solve(int i, int j, int n, vector<int>& piles){
        if (i > j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int take_i = piles[i] + min(solve(i+2, j, n, piles), solve(i+1, j-1, n, piles));

        int take_j = piles[j] + min(solve(i, j-2, n, piles), solve(i+1, j-1, n, piles));

        return dp[i][j] = max(take_i, take_j);
    }
    
    bool stoneGame(vector<int>& piles) {
        int sum = accumulate(piles.begin(), piles.end(), 0);
        int n = piles.size();
        memset(dp, -1, sizeof(dp));
        return ((2 * solve(0, n-1, n, piles) - sum) > 0);
    }
};

// Approach 2: Relative Score Difference Recursion with Memoization
// - `solve(i, j)` returns the maximum net score difference (my score - opponent score) for subarray piles[i..j].
// - Time Complexity: O(N^2)
// - Space Complexity: O(N^2)

class Solution {
public:
    int dp[501][501];

    int solve(int i, int j, int n, vector<int>& piles){
        if (i > j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int take_i = piles[i] - solve(i+1, j, n, piles);
        int take_j = piles[j] - solve(i, j-1, n, piles);

        return dp[i][j] = max(take_i, take_j);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, n-1, n, piles) > 0;
    }
};

// Approach 3: Mathematical / Game Theory Observation (O(1))
// - Since the total number of piles is even and the total sum of stones is odd, the first player can always choose all odd-indexed or all even-indexed piles.
// - One of these choices strictly yields more stones, so the first player (Alex/Alice) always wins.
// - Time Complexity: O(1)
// - Space Complexity: O(1)

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};
