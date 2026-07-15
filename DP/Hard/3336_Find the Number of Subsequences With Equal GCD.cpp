// LeetCode: https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd/
// Concepts: Dynamic Programming, Math, Number Theory

/* 
Approach: Using 3D Dynamic Programming / Memoization. We track the current index in the array, the GCD of the first subsequence, and the GCD of the second subsequence.
For each number, we have three choices: 
1. Add it to the first subsequence.
2. Add it to the second subsequence.
3. Skip it (do not add to either).
Base case: when we reach the end of the array, we check if the GCD of both subsequences are equal and non-zero (meaning both subsequences are non-empty).
TC: O(n * max_val * max_val * log(max_val)) where max_val <= 200
SC: O(n * max_val * max_val)
*/


class Solution {
public:
    int dp[201][201][201];
    int M = 1e9+7;

    int solve(vector<int>& nums, int i, int gcd1, int gcd2) {
        if (dp[i][gcd1][gcd2] != -1)
            return dp[i][gcd1][gcd2];
        int n = nums.size();
        if (i == n) {
            if (gcd1 == gcd2 && gcd1 != 0 && gcd2 != 0)
                return dp[i][gcd1][gcd2] = 1;
            else
                return dp[i][gcd1][gcd2] = 0;
        }

        int firstSeq = solve(nums, i + 1, gcd(gcd1, nums[i]), gcd2);
        int secondSeq = solve(nums, i + 1, gcd1, gcd(gcd2, nums[i]));
        int none = solve(nums, i + 1, gcd1, gcd2);

        return dp[i][gcd1][gcd2] = (0LL + firstSeq + secondSeq + none) % M;
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, 0, 0);
    }
};
