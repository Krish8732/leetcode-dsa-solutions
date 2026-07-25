// LeetCode: https://leetcode.com/problems/find-missing-and-repeated-values/
// Concepts: Array, Hash Table, Math, Matrix

/*
Intuition:
Let grid be an n x n matrix containing numbers from 1 to N (where N = n * n), with one number repeated ('a') and one missing ('b').

Sum of elements:
actualSum - expSum = a - b   =>   d1 = a - b

Sum of squares of elements:
actualSq - expSq = a^2 - b^2   =>   d2 = a^2 - b^2

Since a^2 - b^2 = (a - b) * (a + b):
d2 / d1 = a + b   =>   sumAB = a + b

System of equations:
1) a - b = d1
2) a + b = sumAB

Solving:
a = (d1 + sumAB) / 2
b = a - d1

T.C: O(N) where N = n * n.
S.C: O(1) auxiliary space.
*/

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
