// LeetCode: https://leetcode.com/problems/pascals-triangle/
// Concepts: Array, Dynamic Programming

// Approach: Generate each row by initializing it with 1s. Then for elements between the first and last, calculate the value as the sum of the two elements directly above it in the previous row.
// TC: O(numRows^2) | SC: O(numRows^2)

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       vector<vector<int>> result;
       for(int i = 0; i<numRows; i++){
        vector<int> row(i+1, 1);
        for(int j = 1; j<row.size() - 1; j++){
            row[j] = result[i-1][j-1] + result[i-1][j];
        }
            result.push_back(row);
        }
        return result;
    }
};
