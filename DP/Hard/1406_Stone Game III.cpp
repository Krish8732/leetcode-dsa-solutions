// LeetCode: https://leetcode.com/problems/stone-game-iii/
// Concepts: Dynamic Programming, Minimax, Game Theory, Array

/*
Approach:
We can approach this game theory problem in multiple ways:

1. Top-Down Minimax DP (TLE):
   Alice tries to maximize her score while assuming Bob will minimize her future score (or vice versa).
   Top-down recursion with multiple child calls per state exhibits higher stack/recursion overhead leading to TLE on large inputs.

2. Bottom-Up Minimax DP (Accepted):
   Iterate backwards from n - 1 down to 0. dp[i] represents the maximum score the current player can achieve starting from index i.
   At each step i, the player can take 1, 2, or 3 stones. The opponent plays optimally, leaving the current player the minimum of the remaining outcomes.
   TC: O(n)
   SC: O(n)

3. Top-Down Relative Score Difference DP (Accepted):
   Instead of tracking absolute scores, dp[i] stores the relative score difference (current player score - opponent score) from index i onwards.
   When taking k stones (k = 1, 2, 3), score difference is (stones taken) - solve(i + k).
   TC: O(n)
   SC: O(n)
*/

// Approach 1: Top-Down Minimax DP (TLE)

class Solution {
public:
    int dp[50005];

    int solve(int i, int n, vector<int>& vals) {
        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int take_one =
            vals[i] + min({solve(i + 2, n, vals), solve(i + 3, n, vals),
                           solve(i + 4, n, vals)});
        int take_two = vals[i] + ((i + 1 < n) ? vals[i + 1] : 0) +
                       min({solve(i + 3, n, vals), solve(i + 4, n, vals),
                            solve(i + 5, n, vals)});
        int take_three = vals[i] + ((i + 1 < n) ? vals[i + 1] : 0) +
                         ((i + 2 < n) ? vals[i + 2] : 0) +
                         min({solve(i + 4, n, vals), solve(i + 5, n, vals),
                              solve(i + 6, n, vals)});

        return dp[i] = max({take_one, take_two, take_three});
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int sum = accumulate(stoneValue.begin(), stoneValue.end(), 0);
        memset(dp, -1, sizeof(dp));
        int alexScore = solve(0, n, stoneValue);
        int bobScore = sum - alexScore;

        if (alexScore == bobScore)
            return "Tie";

        return (alexScore > bobScore) ? "Alice" : "Bob";
    }
};


// Approach 2: Bottom-Up Minimax DP (Accepted)
class Solution {
public:

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int sum = accumulate(stoneValue.begin(), stoneValue.end(), 0);

        int dp[50007];
        memset(dp, 0, sizeof(dp));

        for (int i = n-1; i >= 0; i--){
            int take_one = stoneValue[i] + min({dp[i+2], dp[i+3], dp[i+4]});
            int take_two = stoneValue[i] + ((i+1 < n) ? stoneValue[i+1] : 0) + min({dp[i+3], dp[i+4], dp[i+5]});
            int take_three = stoneValue[i] + ((i+1 < n) ? stoneValue[i+1] : 0) + ((i+2 < n) ? stoneValue[i+2] : 0) + min({dp[i+4], dp[i+5], dp[i+6]});

            dp[i] = max({take_one, take_two, take_three});
        }

        int aliceScore = dp[0];
        int bobScore = sum - aliceScore;
        if (aliceScore == bobScore) return "Tie";
        if (aliceScore > bobScore) return "Alice";
        else return "Bob";
    }
};

// Approach 3: Top-Down Score Difference DP (Accepted)

class Solution {
public:
    int n;
    int dp[50005];

    int solve(int i, vector<int>& stoneValue) {
        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int result = stoneValue[i] - solve(i + 1, stoneValue);

        if (i + 1 < n) {
            result = max(result, stoneValue[i] + stoneValue[i + 1] -
                                     solve(i + 2, stoneValue));
        }

        if (i + 2 < n) {
            result =
                max(result, stoneValue[i] + stoneValue[i + 1] +
                                stoneValue[i + 2] - solve(i + 3, stoneValue));
        }

        return dp[i] = result;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        memset(dp, -1, sizeof(dp));
        int diff = solve(0, stoneValue);

        if (diff == 0)
            return "Tie";
        if (diff > 0)
            return "Alice";
        return "Bob";
    }
};
