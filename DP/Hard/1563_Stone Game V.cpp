// LeetCode: https://leetcode.com/problems/stone-game-v/
// Concepts: Dynamic Programming, Array, Game Theory

/*
Intuition:
Alice and Bob play a game with a row of stones. Alice partitions the row into two non-empty groups. Bob calculates the sum of values in each group and gives Alice the group with the smaller sum, while discarding the other group. If the sums are equal, Alice chooses which group to keep. The game continues until only one stone remains. We want to find the maximum score Alice can obtain.

Approach:
1. Dynamic Programming with Memoization:
   For a range [l, r], try partition points `mid` from `l` to `r-1`.
   Calculate the left sum and right sum using a prefix sum array.
   Depending on which sum is smaller, Alice keeps that side and we recurse on it. If they are equal, Alice can choose either side to maximize her score.
   Store the result in a memoization table `t[l][r]` to avoid redundant calculations.

TC: O(N^3) since there are O(N^2) states and for each state we partition at O(N) points.
SC: O(N^2) for the memoization table and O(N) recursion stack space.
*/

class Solution {
public:
    int t[501][501];

    int solve(int n, int l, int r, vector<int>& preSum,
              vector<int>& stoneValue) {
        if (l >= r) {
            return 0;
        }

        if (t[l][r] != -1)
            return t[l][r];

        int maxVal = 0;

        for (int mid = l; mid < r; mid++) {
            int leftSum = preSum[mid] - ((l > 0) ? preSum[l - 1] : 0);
            int rightSum = preSum[r] - preSum[mid];
            if (leftSum == rightSum) {
                maxVal =
                    max(maxVal,
                        leftSum + max(solve(n, mid + 1, r, preSum, stoneValue),
                                      solve(n, l, mid, preSum, stoneValue)));
            } else if (leftSum < rightSum) {
                maxVal =
                    max(maxVal, leftSum + solve(n, l, mid, preSum, stoneValue));
            } else {
                maxVal = max(maxVal, rightSum + solve(n, mid + 1, r, preSum,
                                                      stoneValue));
            }
        }

        return t[l][r] = maxVal;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> preSum(n, 0);

        memset(t, -1, sizeof(t));

        for (int i = 0; i < n; i++) {
            preSum[i] = ((i > 0) ? preSum[i - 1] : 0) + stoneValue[i];
        }

        return solve(n, 0, n - 1, preSum, stoneValue);
    }
};
