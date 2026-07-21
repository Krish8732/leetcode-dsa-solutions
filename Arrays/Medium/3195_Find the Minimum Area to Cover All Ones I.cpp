// LeetCode: https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/
// Concepts: Array, Matrix

// Approach 1: Scan the 2D grid and find the minimum and maximum row and column indices that contain 1.
// The minimum bounding box height is (maxRow - minRow + 1) and width is (maxCol - minCol + 1).
// TC: O(M * N) | SC: O(1)

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int minRow = m, maxRow = -1, minCol = n, maxCol = -1;

        for (int i = 0; i<m; i++){
            for (int j = 0; j<n; j++){
                if (grid[i][j] == 1){
                
                    minRow = min(minRow, i);
                    minCol = min(minCol, j);
                    maxRow = max(maxRow, i);
                    maxCol = max(maxCol, j);
                }
            }
        }
        int minHeight = maxRow - minRow + 1;
        int minWidth = maxCol - minCol + 1;
        int area = minHeight * minWidth;
        return area;
    }
};
