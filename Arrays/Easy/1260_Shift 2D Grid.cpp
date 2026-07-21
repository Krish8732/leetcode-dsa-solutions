// LeetCode: https://leetcode.com/problems/shift-2d-grid/
// Concepts: Array, Matrix, Simulation

// Approach 1 (In-place Reversal): Treat the 2D grid as a 1D array of size r * c.
// Shift by k is equivalent to reversing the entire array, then reversing the first k elements,
// and finally reversing the remaining elements. Map 1D index to 2D using (index / cols, index % cols).
// TC: O(R * C) | SC: O(1)

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r = grid.size();
        int c = grid[0].size();

        int n = r*c;

        k = k % n;
        if (k == 0) return grid;

        auto reverse = [&] (int i, int j){
            while (i < j){
                swap(grid[i/c][i%c], grid[j/c][j%c]);
                i++, j--;
            }
        };

        reverse(0, n-1);
        reverse(0, k-1);
        reverse(k, n-1);

        return grid;
    }
};
