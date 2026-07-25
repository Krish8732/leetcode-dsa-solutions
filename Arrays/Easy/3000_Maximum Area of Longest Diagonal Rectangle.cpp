// LeetCode: https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle/
// Concepts: Array, Geometry, Math

/*
Intuition:
We are given a 2D array `dimensions` where `dimensions[i] = [length_i, width_i]`.
The diagonal squared of a rectangle is `l^2 + w^2` (by Pythagorean theorem).
We want to find the rectangle with the maximum diagonal length. If multiple rectangles have the same maximum diagonal, return the one with the maximum area (`l * w`).

1. Iterate through each rectangle `[l, b]`.
2. Compute `diag = l^2 + b^2` and `area = l * b`.
3. If `diag > maxDiag`, update both `maxDiag = diag` and `maxArea = area`.
4. If `diag == maxDiag`, update `maxArea = max(maxArea, area)`.
5. Return `maxArea`.

T.C: O(N) where N is the number of rectangles.
S.C: O(1) auxiliary space.
*/

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea = 0;
        int maxDiag = 0;
        for (int i = 0; i < dimensions.size(); i++) {
            int b = dimensions[i][1];
            int l = dimensions[i][0];
            int diag = (l * l) + (b * b);
            int area = l * b;
            if (diag > maxDiag) {
                maxDiag = diag;
                maxArea = area;
            } else if (diag == maxDiag) {
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};
