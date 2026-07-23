// Leetcode: https://leetcode.com/problems/range-addition-ii/
// Concepts: Array, Math

/*
Intuition:
Each operation op = [ai, bi] increments all elements in the sub-matrix from (0, 0) to (ai - 1, bi - 1).
The elements that get incremented the most number of times will be in the intersection of all operation sub-matrices.
Therefore, the maximum value elements will lie within the sub-matrix of size min(ai) * min(bi).

- Initialize minRow = m and minCol = n.
- Iterate over each op in ops and update minRow = min(minRow, op[0]) and minCol = min(minCol, op[1]).
- The answer is minRow * minCol.

T.C: O(k) where k is the number of operations in ops
S.C: O(1)
*/

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if (ops.empty()) {
            return m * n;
        }
        
        int minRow = m;
        int minCol = n;
        
        for (const auto& op : ops) {
            minRow = min(minRow, op[0]);
            minCol = min(minCol, op[1]);
        }
        
        return minRow * minCol;
    }
};
