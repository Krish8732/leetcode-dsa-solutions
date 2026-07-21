// LeetCode: https://leetcode.com/problems/reverse-integer/
// Concepts: Math

/*
Approach 1 (Using 64-bit Integer): Copy the input integer into a 64-bit variable (long long)
to prevent overflow during intermediate calculations. Reverse the integer digits one by one.
If the reversed value exceeds the limits of a 32-bit signed integer (INT_MIN or INT_MAX), return 0.
Otherwise, return the reversed value casted back to 32-bit int.

TC: O(log10(X)) | SC: O(1)
*/

class Solution {
public:
    int reverse(int x) {
        long long n = x;
        bool negative = (n < 0); 
        if ( n == 0) return 0;
        if (n < 0) n = -n;

        long long temp = 0;
        while(n > 0){
            int digit = n%10;
            temp = temp*10 + digit;
            if (temp > INT_MAX) return 0;
            n /= 10;
        }

        if (negative == true) temp = -temp;
        if (temp < INT_MIN) return 0;
        return (int)temp;
    }
};
