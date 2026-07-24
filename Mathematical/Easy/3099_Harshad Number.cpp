// LeetCode: https://leetcode.com/problems/harshad-number/
// Concepts: Math, Digit Sum

/*
Intuition:
A Harshad number (or Niven number) is an integer that is divisible by the sum of its digits.

1. Extract all digits of `x` using modulo 10 and division by 10 to calculate digit sum `sum`.
2. Check if original number `copy % sum == 0`.
3. If divisible, return `sum`; otherwise, return -1.

T.C: O(log10(x)) to sum digits of x.
S.C: O(1) auxiliary space.
*/

class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = 0;
        int copy = x;
        while ( x > 0 ){
            int n = x % 10;
            x /= 10;
            sum += n;
        }
        if ( copy % sum == 0 ) return sum;
        return - 1;
    }
};
