// LeetCode: https://leetcode.com/problems/flip-square-submatrix-vertically/
// Concepts: Array, Matrix, Two Pointers, Simulation

/*
Intuition:
We are given an m x n 2D grid, along with coordinates (x, y) specifying the top-left corner of a k x k square submatrix.
We need to flip this k x k submatrix vertically in-place.

1. Maintain two row pointers `i = x` (starting top row of submatrix) and `j = x + k - 1` (starting bottom row of submatrix).
2. While `i < j`, iterate column index `c` from `y` to `y + k - 1` and swap `grid[i][c]` with `grid[j][c]`.
3. Increment `i` and decrement `j`.

T.C: O(k^2)
S.C: O(1) auxiliary space
*/

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x,
                                         int y, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int i = x;
        int j = x + k - 1;

        while (i < j) {
            for (int c = y; c < y + k; c++) {
                swap(grid[i][c], grid[j][c]);
            }
            i++, j--;
        }

        return grid;
    }
};
