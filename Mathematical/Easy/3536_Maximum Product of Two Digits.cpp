// LeetCode: https://leetcode.com/problems/maximum-product-of-two-digits/
// Concepts: Math

/*
Intuition:
Find the largest digit and the second largest digit (or count if the largest digit appears multiple times).
Return maxNum * secMax if maxNum appears once, else maxNum * maxNum.

T.C: O(log10(n))
S.C: O(1)
*/

class Solution {
public:
    int maxProduct(int n) {
        int maxNum = 0;
        int secMax = 0;
        int maxNumCnt = 0;
        int temp = n;

        while (temp > 0) {
            int digit = temp % 10;
            maxNum = max(maxNum, digit);
            temp /= 10;
        }

        temp = n;

        while (temp > 0) {
            int digit = temp % 10;

            if (digit == maxNum)
                maxNumCnt++;
            else
                secMax = max(secMax, digit);
            temp /= 10;
        }

        return (maxNumCnt < 2) ? (maxNum * secMax) : (maxNum * maxNum);
    }
};
