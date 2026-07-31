// LeetCode: https://leetcode.com/problems/richest-customer-wealth/
// Concepts: Array, Matrix, Iteration

/*
Intuition & Approach:
The wealth of a customer is the sum of money in all their bank accounts (sum of elements in a row).
We iterate through each row `i` of the grid `accounts`, calculate the sum of elements in `accounts[i]`, and update `maxWealth` with the maximum row sum found.

This is the optimal approach as every element in the grid must be visited at least once.

T.C: O(M * N) where M is the number of customers (rows) and N is the number of banks (columns).
S.C: O(1) auxiliary space.
*/

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        for (int i = 0; i<accounts.size(); i++){
            int wealth = 0;
            for (int j = 0; j<accounts[i].size(); j++){
            wealth += accounts[i][j];
            }
            maxWealth = max(maxWealth, wealth);
        }
        return maxWealth;
    }
};
