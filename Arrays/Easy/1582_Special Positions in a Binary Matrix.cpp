// LeetCode: https://leetcode.com/problems/special-positions-in-a-binary-matrix/
// Concepts: Array, Matrix

/*
Approach 1 (Zero Counting in Rows & Columns - User's Submission):
Intuition:
Count the number of 0s in each row and column. A cell mat[i][j] = 1 is special if the number of 0s in row i is (n - 1)
and the number of 0s in column j is (m - 1). This is equivalent to checking if the row and column sum of 1s is exactly 1.
TC: O(m * n) | SC: O(m + n)
*/

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> rowZeroCnt(m, 0);
        vector<int> colZeroCnt(n, 0);

        for (int row = 0; row < m; row++) {
            int zeroCnt1 = 0;
            for (int col = 0; col < n; col++) {
                if (mat[row][col] == 0)
                    zeroCnt1++;
            }
            rowZeroCnt[row] = zeroCnt1;
        }

        for (int col = 0; col < n; col++) {
            int zeroCnt2 = 0;
            for (int row = 0; row < m; row++) {
                if (mat[row][col] == 0)
                    zeroCnt2++;
            }
            colZeroCnt[col] = zeroCnt2;
        }

        int specialPos = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0)
                    continue;

                if ((rowZeroCnt[i] == n - 1) && (colZeroCnt[j] == m - 1)) {
                    specialPos++;
                }
            }
        }

        return specialPos;
    }
};

/*
Approach 2 (Precomputing Row and Column Sums of 1s):
Intuition:
Instead of counting 0s, we can directly count the number of 1s in each row and column in a single pass over the matrix.
Then, we iterate through the matrix again. If mat[i][j] == 1, rowSum[i] == 1, and colSum[j] == 1, we increment the special positions counter.
This is slightly cleaner and faster as it avoids counting 0s and relies on 1s directly.
TC: O(m * n) | SC: O(m + n)
*/

/*
Approach 3 (Space-Optimized Row Checking - O(1) Auxiliary Space):
Intuition:
To avoid using O(m + n) extra space for count arrays, we can process row-by-row.
For each row:
1. Count the number of 1s in the row.
2. If there is exactly one 1 in the row, note down its column index 'colIdx'.
3. Verify if that column 'colIdx' has exactly one 1 across all rows.
4. If it does, we have found a special position.
This allows us to solve the problem without storing state for all rows and columns.
TC: O(m * n) | SC: O(1) (excluding input)
*/
