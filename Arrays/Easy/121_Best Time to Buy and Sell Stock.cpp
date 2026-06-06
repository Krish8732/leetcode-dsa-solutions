// Leetcode: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Concepts: Array, Greedy

// Approach: track the minimum price seen so far and update the best profit at each step.

// T.C: O(n)
// S.C: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        int n = prices.size();
        for(int i = 0; i<n; i++){
            int price = prices[i];
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }
     return maxProfit;
    }
};