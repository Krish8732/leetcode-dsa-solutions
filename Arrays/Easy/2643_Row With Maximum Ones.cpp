// LeetCode: https://leetcode.com/problems/row-with-maximum-ones/
// Concepts: Array, Matrix, Counting

/*
Intuition:
Given an m x n binary matrix `mat`, find the 0-indexed row that has the maximum number of 1s, and the number of 1s in that row.
If there are multiple rows with the maximum count, return the row with the smallest index.

Iterate through each row `i`, count the 1s, and update `maxOnesCnt` and `index` if `onesCnt > maxOnesCnt` (using strict `>` ensures smallest row index on tie).

T.C: O(M * N) where M is number of rows and N is number of columns.
S.C: O(1) auxiliary space.
*/

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int maxOnesCnt = 0;
        int index = 0;
        for (int i = 0; i < m; i++) {
            int onesCnt = 0;
            for (int j = 0; j < n; j++) {
                onesCnt += mat[i][j];
            }
            if (onesCnt > maxOnesCnt) {
                maxOnesCnt = onesCnt;
                index = i;
            }
        }
        return {index, maxOnesCnt};
    }
};
