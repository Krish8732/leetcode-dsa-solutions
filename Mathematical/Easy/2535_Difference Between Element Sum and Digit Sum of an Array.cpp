// LeetCode: https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/
// Concepts: Array, Math, Digit Sum

/*
Intuition:
We are given a positive integer array `nums`.
- `elementSum`: sum of all elements in `nums`.
- `digitSum`: sum of all digits of all elements in `nums`.
Return `|elementSum - digitSum|`.

1. Compute total element sum `elSum`.
2. Compute digit sum `digiSum`: for numbers < 10, add directly; for numbers >= 10, extract digits using modulo 10 and division by 10.
3. Return `abs(elSum - digiSum)`.

T.C: O(N * log10(M)) where N is length of nums and M is maximum element value.
S.C: O(1) auxiliary space.
*/

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elSum = 0;
        for (int x : nums) {
            elSum += x;
        }
        int digiSum = 0;
        for (int x : nums) {
            if (x < 10)
                digiSum += x;
            else {
                int sum = 0;
                int a;
                while (x > 0) {
                    a = x % 10;
                    x = x / 10;
                    sum += a;
                }
                digiSum += sum;
            }
        }
        return abs(elSum - digiSum);
    }
};
