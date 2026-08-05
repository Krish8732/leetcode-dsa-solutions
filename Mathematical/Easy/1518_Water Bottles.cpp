// LeetCode: https://leetcode.com/problems/water-bottles/
// Concepts: Math, Simulation

// Approach 1 (Simulation):
// Intuition:
// We simulate the drinking and exchanging process. In each step, we divide the empty bottles by numExchange to find how many new full bottles we get, and track the remaining empty bottles using modulo. We repeat this until we have fewer empty bottles than required for exchange.
// TC: O(log_(numExchange) (numBottles)) | SC: O(1)

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cnt = numBottles;
        int emptyBottles = numBottles;
        while (emptyBottles >= numExchange) {
            numBottles = emptyBottles / numExchange;
            emptyBottles = emptyBottles % numExchange + numBottles;
            cnt += numBottles;
        }
        return cnt;
    }
};

// Approach 2 (Optimal Math Formula):
// Intuition:
// Each exchange requires trading numExchange empty bottles to get 1 full bottle. This effectively reduces our total empty bottles count by (numExchange - 1) for each additional bottle we get to drink.
// Since we must start with at least numExchange empty bottles to make the first exchange, the maximum number of additional bottles we can get is (numBottles - 1) / (numExchange - 1).
// Therefore, the total bottles we can drink is numBottles + (numBottles - 1) / (numExchange - 1).
// TC: O(1) | SC: O(1)

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles + (numBottles - 1) / (numExchange - 1);
    }
};
