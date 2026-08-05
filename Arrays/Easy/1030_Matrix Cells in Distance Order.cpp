// LeetCode: https://leetcode.com/problems/matrix-cells-in-distance-order/
// Concepts: Array, Geometry, Sorting

/*
Approach:
Intuition:
We can generate all coordinates in the grid and insert them into a 2D vector. Then, we sort this vector using a custom lambda function that calculates the Manhattan distance to the center coordinate (rCenter, cCenter) for each cell and sorts them in ascending order of their distances. This simplifies the implementation by avoiding auxiliary data structures.

Note: We can optimize this to O(R * C) time by traversing cells layer-by-layer (rings) outwards from the center, so they are naturally sorted by distance without requiring a sort.

TC: O(R * C * log(R * C)) - where R is rows and C is cols, since we sort all R * C cells.
SC: O(log(R * C)) - for the recursion stack of the sorting algorithm.
*/

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> result;
        result.reserve(rows * cols);
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                result.push_back({r, c});
            }
        }
        
        sort(result.begin(), result.end(), [rCenter, cCenter](const vector<int>& a, const vector<int>& b) {
            return (abs(a[0] - rCenter) + abs(a[1] - cCenter)) < (abs(b[0] - rCenter) + abs(b[1] - cCenter));
        });
        
        return result;
    }
};
