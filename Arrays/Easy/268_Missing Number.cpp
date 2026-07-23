// Leetcode: https://leetcode.com/problems/missing-number/
// Concepts: Array, Math, Bit Manipulation

/*
Intuition (Sum Formula - Optimal):
The expected sum of numbers from 0 to n is given by the formula:
expectedSum = n * (n + 1) / 2

By subtracting the sum of all elements in nums from expectedSum, 
the remaining value is the missing number.

T.C: O(n)
S.C: O(1)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, sum2 = 0;
        sum = (n * (n + 1)) / 2;
        for (int i = 0; i < nums.size(); i++) {
            sum2 += nums[i];
        }
        int mn = sum - sum2;
        return mn;
    }
};
