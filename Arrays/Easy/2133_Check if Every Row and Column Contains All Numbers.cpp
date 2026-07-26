// LeetCode: https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/
// Concepts: Array, Hash Table, Matrix, In-Place Marking

/*
Intuition:
An n x n matrix is valid if every row and every column contains all integers from 1 to n.
Since each row/column has length n, this implies each number from 1 to n must appear exactly once per row and column without duplicates.

Approach 1: Two Pass (Separate Visited Vectors for Rows and Columns)
Check duplicate presence in each row independently using a boolean array, then repeat the process for each column.
T.C: O(n^2)
S.C: O(n) space for boolean vector per row/col check.

Approach 2: Single Pass with Hash Sets / Bitsets / Frequency Matrix
Instead of separate passes, validate both rows and columns in a single traversal using n frequency/boolean vectors for columns while checking rows on the fly.
T.C: O(n^2)
S.C: O(n^2) auxiliary space for matrix marking (or O(n) with sum/bitset checks).

Approach 3: Optimal In-Place Index Marking (O(1) Auxiliary Space)
Since values are strictly in range [1, n], use element signs as visited markers:
- Row Pass: mark `matrix[i][val-1]` as negative. If already negative, return `false`.
- Column Pass: check if `matrix[val-1][j]` is negative, then flip it back to positive to mark visited. If already positive, return `false`.
This avoids an explicit restoration loop.
T.C: O(n^2)
S.C: O(1) auxiliary space.
*/

// Approach 1: Two Pass (Boolean Visited Array)
class SolutionBruteForce {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            vector<bool> seen(n, false);
            for (int j = 0; j < n; j++) {
                if (seen[matrix[i][j] - 1]) return false;
                seen[matrix[i][j] - 1] = true;
            }
        }

        for (int j = 0; j < n; j++) {
            vector<bool> seen(n, false);
            for (int i = 0; i < n; i++) {
                if (seen[matrix[i][j] - 1]) return false;
                seen[matrix[i][j] - 1] = true;
            }
        }
        return true;
    }
};

// Approach 2: Single Pass (Column Tracking Array)
class SolutionSinglePass {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<bool>> colSeen(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            vector<bool> rowSeen(n, false);
            for (int j = 0; j < n; j++) {
                int val = matrix[i][j] - 1;
                if (rowSeen[val] || colSeen[j][val]) return false;
                rowSeen[val] = true;
                colSeen[j][val] = true;
            }
        }
        return true;
    }
};

// Approach 3: Optimal In-Place Marking O(1) Auxiliary Space
class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Check rows in-place (mark by making elements negative)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = abs(matrix[i][j]) - 1;
                if (matrix[i][val] < 0) return false;
                matrix[i][val] *= -1;
            }
        }

        // Check columns in-place (check for negative and flip back to positive, avoiding an explicit restoration loop)
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                int val = abs(matrix[i][j]) - 1;
                if (matrix[val][j] > 0) return false; // Already flipped positive in this column check
                matrix[val][j] *= -1;                 // Mark visited by making positive again
            }
        }

        return true;
    }
};
