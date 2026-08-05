// LeetCode: https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/
// Concepts: Array, Math, Simulation

/*
Note: The brute-force approach would involve simulating the entire m x n matrix, performing the increments for each query in indices, and then counting the odd cells. This takes O(L * (m + n) + m * n) time and O(m * n) space, where L is the number of indices.
*/

// Approach 1 (Space-Optimized Simulation):
// Intuition:
// We can track the increment count for each row and column using rowCount and colCount arrays. A cell (i, j) is incremented rowCount[i] + colCount[j] times. We can iterate through the entire matrix to check which cells have an odd sum.
// TC: O(m * n + L) | SC: O(m + n)

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> rowCount (m, 0);
        vector<int> colCount (n, 0);
        for ( auto &it : indices ){
            int r = it[0];
            int c = it[1];
            rowCount[r]++;
            colCount[c]++;
        }
        int cnt = 0;
        for ( int i = 0; i < m; i++ ){
            for ( int j = 0; j < n; j++ ){
                if ( (rowCount[i] + colCount[j]) % 2 != 0 ) cnt++;
            }
        }
        return cnt;
    }
};

// Approach 2 (Optimal Math Counting):
// Intuition:
// Instead of checking all cells individually, we can count how many rows and columns have an odd number of increments. A cell (i, j) will have an odd value if and only if either its row has an odd count and its column has an even count, or its row has an even count and its column has an odd count.
// TC: O(m + n + L) | SC: O(m + n)

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);
        for (auto& it : indices) {
            int r = it[0];
            int c = it[1];
            rowCount[r]++;
            colCount[c]++;
        }
        int cnt = 0;
        int evenRows = 0, evenCols = 0, oddRows = 0, oddCols = 0;

        for (int i = 0; i < m; i++) {
            if (rowCount[i] % 2)
                oddRows++;
            else
                evenRows++;
        }

        for (int i = 0; i < n; i++) {
            if (colCount[i] % 2)
                oddCols++;
            else
                evenCols++;
        }

        cnt = (evenRows * oddCols) + (evenCols * oddRows);

        return cnt;
    }
};
