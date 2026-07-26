// LeetCode: https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/
// Concepts: Array, Greedy, Sorting

/*
Intuition (Greedy Approach):
We must buy all candies eventually. To minimize the total cost, we should maximize the value of candies we get for free.
A candy is free only if its price is less than or equal to the minimum of two bought candies.
By sorting prices in descending order, we pick the two highest-priced candies first and take the third highest-priced candy for free.
Repeating this group by group maximizes the discount received.

T.C: O(n log n) due to sorting
S.C: O(1) auxiliary space (or O(log n) sorting space)
*/

class Solution {
public:
    int minimumCost(vector<int>& cost) {

        int counter = 1;
        int totalCost = 0;
        sort(begin(cost), end(cost), greater<int>());

        for (int i = 0; i < cost.size(); i++) {
            if (counter == 3) {
                counter = 1;
                continue;
            }
            totalCost += cost[i];
            counter++;
        }

        return totalCost;
    }
};
