// Leetcode: https://leetcode.com/problems/find-missing-and-repeated-values/
//Concepts: Array, Math, Grid

//Approach: use mathematical approach - calculate expected sum and sum of squares using formulas, compute actual sum and sum of squares from grid. Use two equations (d1 = actualSum - expectedSum, d2 = actualSq - expectedSq) to find the repeated and missing numbers.

//T.C: O(n^2)
//S.C: O(1)

class Solution {
public:
    typedef long long ll;

    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        ll n = grid.size();
        ll N = n * n;
        ll actualSum = 0;
        ll actualSq = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ll val = grid[i][j];
                actualSum += val;
                actualSq += val * val;
            }
        }

        ll expSum = N * (N + 1) / 2;
        ll expSq = N * (N + 1) * (2 * N + 1) / 6;

        ll d1 = actualSum - expSum;
        ll d2 = actualSq - expSq;

        ll sumAB = d2 / d1;

        ll a = (d1 + sumAB) / 2;
        ll b = a - d1;

        return {(int)a, (int)b};
    }
};
