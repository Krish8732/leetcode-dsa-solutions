// LeetCode: https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/
// Concepts: Math, Digit Simulation

// Approach (Iterative Simulation):
// Intuition:
// We need to find the smallest integer >= n such that the product of its digits is divisible by t.
// We can start checking from n. In each step, we check if the digit product of the current number is divisible by t.
// Since we want the smallest number, the first number we find satisfying the condition is our answer.
// TC: O(k * log10(n)) where k is the number of increments required to find a valid solution | SC: O(1)

class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            int product = 1;
            int x = n;
            while (x > 0) {
                product *= (x % 10);
                x /= 10;
            }
            if (product % t == 0) {
                return n;
            }
            n++;
        }
        return n;
    }
};
