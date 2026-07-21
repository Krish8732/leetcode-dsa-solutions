// LeetCode: https://leetcode.com/problems/minimum-path-sum/
// Concepts: Dynamic Programming, Array, Matrix

// Approach 1 (Bottom-Up Dynamic Programming / Space-Optimized): Update the grid in-place.
// The minimum path sum to grid[i][j] is grid[i][j] + min(grid[i-1][j], grid[i][j-1]).
// Handle boundary conditions for the first row and first column.
// TC: O(M * N) | SC: O(1)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
       
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue; 
                if (i == 0) grid[i][j] += grid[i][j - 1];  else if (j == 0) grid[i][j] += grid[i - 1][j];
                else grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]); 
            }
        }
        
        return grid[m - 1][n - 1]; 
    }
};
