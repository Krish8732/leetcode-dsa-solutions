// Leetcode: https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/
//Concepts: Array, Counting

//Approach: iterate through array, count positive and negative numbers, return maximum of the two counts.

//T.C: O(n) where n is size of array
//S.C: O(1)

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pc = 0, nc = 0;

        for (auto n : nums) {
            if (n > 0) {
                pc++;
            } else if (n < 0) {
                nc++;
            }
        }

        return max(pc, nc);
    }
};
