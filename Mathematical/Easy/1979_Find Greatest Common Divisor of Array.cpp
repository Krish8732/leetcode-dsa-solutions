// LeetCode: https://leetcode.com/problems/find-greatest-common-divisor-of-array/
// Concepts: Array, Math, Number Theory

// Approach 1: Find the minimum and maximum elements in a single scan.
// Return their greatest common divisor (GCD) using std::gcd or Euclid's algorithm.
// TC: O(N + log(min(minElem, maxElem))) | SC: O(1)

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minElem = 10000, maxElem = 0;
        for (int x : nums) {
            minElem = min(x, minElem);
            maxElem = max(x, maxElem);
        }

        if (minElem == maxElem)
            return minElem;
        else
            return gcd(minElem, maxElem);
    }
};
