// LeetCode: https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/
// Concepts: Math

/*
Approach: Extract digits of n from right to left using modulo 10.
Maintain a sum of non-zero digits and build the concatenated number using a power-of-ten multiplier.
Return sum * concatenated_number.
TC: O(log10 n) - Digits are processed one by one.
SC: O(1) - Uses constant extra space.
*/

class Solution {
public:
    typedef long long ll;
    ll sumAndMultiply(int n) {
        if (n == 0)
            return 0;
        ll mul = 1;
        ll sum = 0;
        ll num = 0;

        while (n > 0) {
            int curr = n % 10;
            n /= 10;
            if (curr != 0)
                num = num + (curr * mul), mul *= 10;
            sum += curr;
        }

        return sum * num;
    }
};
