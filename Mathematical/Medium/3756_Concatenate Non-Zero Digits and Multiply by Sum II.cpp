// LeetCode: https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-ii/
// Concepts: Prefix Sum, Math, String, Number Theory

/*
Approach:
Intuition:
To answer each range query [L, R] in O(1) time:
1. Sum of Digits: We can precompute a standard prefix sum of the digits. The sum in range [L, R] is simply `preSum[R] - preSum[L-1]`.
2. Concatenated Value: Let `num[i]` be the value formed by concatenating all non-zero digits up to index `i`.
   - If we want the concatenated value of non-zero digits strictly in the range [L, R], we need to remove the contribution of the prefix [0, L-1] from `num[R]`.
   - In place-value arithmetic, removing a prefix `numBefore` from `num[R]` is done by shifting `numBefore` to the left by the number of non-zero digits in [L, R] (let's call this count `k`) and subtracting it.
   - Specifically: `x = (num[R] - numBefore * 10^k) % M`.
3. Precomputations:
   - `preSum[i]`: Prefix sum of digits up to index `i`.
   - `num[i]`: Value of concatenated non-zero digits up to index `i` modulo M.
   - `nonZeroCnt[i]`: Number of non-zero digits up to index `i` (used to compute `k` for any range).
   - `pow10[i]`: Powers of 10 modulo M.

TC: O(n + q) - O(n) precomputation and O(1) per query.
SC: O(n) - Precomputed prefix arrays.
*/

class Solution {
public:
    int M = 1e9 + 7;
    typedef long long ll;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int m = queries.size();
        vector<ll> preSum(n, 0);
        vector<int> nonZeroCnt(n, 0);
        vector<ll> num(n, 0);
        vector<int> result(m, 0);
        vector<ll> pow10(n + 1, 0);

        pow10[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % M;
        }

        for (int i = 0; i < n; i++) {
            int digit = s[i] - '0';

            if (digit != 0) {
                nonZeroCnt[i] = (i > 0) ? nonZeroCnt[i - 1] + 1 : 1;
                num[i] = (i > 0) ? (num[i - 1] * 10 + digit) % M : digit;
            } else {
                nonZeroCnt[i] = (i > 0) ? nonZeroCnt[i - 1] : 0;
                num[i] = (i > 0) ? num[i - 1] : digit;
            }

            preSum[i] = (i > 0) ? preSum[i - 1] + digit : digit;
        }

        for (int i = 0; i < m; i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            ll sum = preSum[r] - ((l > 0) ? preSum[l - 1] : 0);

            ll numBefore = (l == 0) ? 0 : num[l - 1];

            int k = nonZeroCnt[r] - ((l > 0) ? nonZeroCnt[l - 1] : 0);

            ll x = (num[r] - (numBefore * pow10[k] % M) + M) % M;

            result[i] = (int)((x * sum) % M);
        }

        return result;
    }
};
