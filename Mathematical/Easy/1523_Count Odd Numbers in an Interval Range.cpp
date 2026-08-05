// LeetCode: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
// Concepts: Math

// Approach 1 (Interval Adjustment):
// Intuition:
// Make high and low odd by bringing them near if not odd (decrement high if even, increment low if even). Once both are guaranteed to be odd, the total odd numbers can be found by (high - low) / 2 + 1, since there are half jumps between two odd numbers.
// TC: O(1) | SC: O(1)

class Solution {
public:
    int countOdds(int low, int high) {
        if (high % 2 == 0){
            high--;
        }
        if (low % 2 == 0){
            low++;
        }
        return (high-low)/ 2 + 1;
    }
};

// Approach 2 (Optimal Formula):
// Intuition:
// The count of odd numbers in range [1, x] is given by (x + 1) / 2.
// Therefore, the count of odd numbers in range [low, high] is the count of odds in [1, high] minus the count of odds in [1, low - 1].
// Total Odds = ((high + 1) / 2) - (low / 2).
// TC: O(1) | SC: O(1)

class Solution {
public:
    int countOdds(int low, int high) {
        return (high + 1) / 2 - low / 2;
    }
};
