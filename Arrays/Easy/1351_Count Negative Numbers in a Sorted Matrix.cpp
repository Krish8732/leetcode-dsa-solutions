// LeetCode: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
// Concepts: Array, Binary Search, Matrix

// Approach 0 (Brute Force / Naive Iteration - Concept only):
// Intuition:
// We can iterate over all elements of the matrix using nested loops and count the negatives.
// Alternatively, we can optimize slightly by checking the last element of each row. If the last element is >= 0,
// we can skip the row entirely because the row is sorted in non-increasing order (meaning all elements in that row are non-negative).
// If we do search a row, we iterate from left to right, find the first negative index 'idx', and add 'n - idx' to the result before moving to the next row.
// TC: O(m * n) | SC: O(1)

// Approach 1 (Staircase Search / Binary-Search-like 2D Traversal - Optimal):
// Intuition:
// Since both the rows and columns of the matrix are sorted in non-increasing order,
// we can start from the bottom-left corner of the grid (row = m - 1, col = 0).
// If the current element grid[row][col] is negative, then all elements to its right in the same row
// must also be negative (since the row is sorted in non-increasing order).
// There are (n - col) such elements. We add this count to our result and move up to the previous row (row--).
// If the current element is non-negative (>= 0), we move right to the next column (col++) to find where negatives start.
// TC: O(m + n) | SC: O(1)

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int row = m - 1;
        int col = 0;
        int result = 0;

        while (row >= 0 && col < n) {
            if (grid[row][col] >= 0) {
                col++;
            } else {
                result += (n - col);
                row--;
            }
        }
        return result;
    }
};

// Approach 2 (Binary Search per Row - Somewhat Optimized):
// Intuition:
// For each row, we can use binary search to locate the first negative number.
// Since each row is sorted in non-increasing order, once we find the first negative index 'mid',
// all elements from 'mid' to the end of the row 'n - 1' are also negative, giving (n - mid) negatives.
// We can also early break our rows loop from the bottom if a row's last element is non-negative,
// because all rows above it will also have only non-negative elements at their ends (or completely non-negative).
// TC: O(m * log(n)) | SC: O(1)

class Solution2 {
public:
    int cntNegatives(const vector<int>& row, int n) {
        int ans = 0;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (row[mid] >= 0) {
                l = mid + 1;
            } else {
                ans = n - mid;
                r = mid - 1;
            }
        }
        return ans;
    }

    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int totalNegatives = 0;

        for (int row = m - 1; row >= 0; row--) {
            int n = grid[row].size();
            if (grid[row][n - 1] >= 0)
                break;
            totalNegatives += cntNegatives(grid[row], n);
        }
        return totalNegatives;
    }
};
