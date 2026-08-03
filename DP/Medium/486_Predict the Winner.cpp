// LeetCode: https://leetcode.com/problems/predict-the-winner/
// Concepts: Dynamic Programming, Recursion, Game Theory, Minimax

// Intuition & Explanation:
// - This is a classic Game Theory / Minimax problem. We focus on maximizing the profit of Player 1.
// - Since both players play optimally, Player 2 will make choices that minimize Player 1's remaining profit.
// - Therefore, for Player 1's turn (picking index i or j), we evaluate all future possibilities after Player 2's optimal move 
//   and take the MINIMUM from those scenarios (since Player 2 leaves us with the worst-case outcome for that branch).
// - Player 1 then chooses the MAXIMUM between picking nums[i] and picking nums[j].
// - A local greedy choice (e.g., taking max(nums[i], nums[j]) at each turn) fails because picking a larger number now 
//   might expose an even larger number for the opponent in subsequent turns.
//
// Note on Memoization & Complexity:
// - Standard recursion without memoization visits overlapping subproblems, resulting in exponential O(2^N) time complexity.
// - By adding state lookup (if (dp[i][j] != -1) return dp[i][j];) and memoizing the state (return dp[i][j] = max(...);),
//   there are at most N * N subproblems (i, j pairs).
// - TC: O(N^2) | SC: O(N^2)

class Solution {
public:
    int dp[21][21];
    int solve(int i, int j, int n, vector<int>& nums) {
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int take_i = nums[i] + min(solve(i + 2, j, n, nums),
                                   solve(i + 1, j - 1, n, nums));
        int take_j = nums[j] + min(solve(i, j - 2, n, nums),
                                   solve(i + 1, j - 1, n, nums));

        return dp[i][j] = max(take_i, take_j);
    }

    bool predictTheWinner(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return ((2 * solve(0, n - 1, n, nums) - sum) >= 0);
    }
};
