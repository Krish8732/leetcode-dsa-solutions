// Leetcode: https://leetcode.com/problems/find-missing-and-repeated-values/
//Concepts: Array, Indexing Mark

//Approach: mark visited numbers by making corresponding grid positions negative based on 1D index mapping. When we encounter a number whose mapped position is already negative, it's the repeated number. After marking all, the positive value remaining is the missing number. Uses the array itself as a hash map.

//T.C: O(n^2)
//S.C: O(1)

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int missing, rep;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int curr = abs(grid[i][j]);
                int row = (curr - 1) / n;
                int col = (curr - 1) % n;

                if (grid[row][col] < 0) {
                    rep = curr;
                    continue;
                }
                grid[row][col] *= -1;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    missing = i * n + (j + 1);
                    break;
                }
            }
        }

        return {rep, missing};
    }
};
