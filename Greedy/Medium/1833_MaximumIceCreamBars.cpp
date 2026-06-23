// LeetCode: https://leetcode.com/problems/maximum-ice-cream-bars/
// Concepts: Greedy, Sorting, Counting Sort

// Approach 1 (Counting Sort / Bucket Sort): Store frequency of each cost. Greedily buy ice creams starting from the lowest cost.
// TC: O(N + maxC) | SC: O(maxC) where maxC is the maximum value in costs.

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxC = *max_element(costs.begin(), costs.end());

        vector<int> count(maxC + 1, 0);

        for (int c : costs) {
            count[c]++;
        }

        int n = count.size();
        int total = 0;

        for (int i = 1; i < n; i++) {
            if (count[i] == 0)
                continue;

            if (coins < i)
                break;

            int buy = min(count[i], coins / i);
            coins -= buy * i;
            total += buy;
        }

        return total;
    }
};

// Approach 2 (Sorting & Greedy): Sort the costs in ascending order and greedily pick the cheapest ice cream bars first.
// TC: O(N log N) | SC: O(log N)

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(begin(costs), end(costs));

        int cnt = 0;

        for (int c : costs){
            if (c > coins) break;
            cnt++;
            coins -= c;
        }

        return cnt;
    }
};
