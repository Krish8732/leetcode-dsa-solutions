// Leetcode: https://leetcode.com/problems/palindrome-number/
// Concepts: Math, Digit Manipulation

// Approach: Reverse the digits of the number and compare the reversed value with the original number.

// TC: O(log n) where n is the input number (number of digits)
// SC: O(1)

class Solution {
public:
    bool isPalindrome(int x) {
        long long revn = 0;
        int n = x;
        int temp = n;
        while (n > 0) {
            int ld = n % 10;
            revn = (revn * 10) + ld;
            n = n / 10;
        }

        if (revn == temp)
            return true;
        else
            return false;
    }
};