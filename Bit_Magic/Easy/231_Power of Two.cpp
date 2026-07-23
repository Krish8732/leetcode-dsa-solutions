// Leetcode: https://leetcode.com/problems/power-of-two/
// Concepts: Math, Bit Manipulation

/*
Approach 1: Logarithm
If n is a power of 2, then log2(n) will produce an exact integer value.
Comparing double precision log2(n) with integer cast log2(n) checks if log2(n) has no fractional component.
Note: Floating-point precision issues can make this unreliable for large values.

T.C: O(1)
S.C: O(1)
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        double num1 = log2(n);
        int num2 = log2(n);
        return (num1 == num2);
    }
};

/*
Approach 2: Iterative Multiplication
Start with 1 (2^0) and continuously double it while pwr <= n.
If pwr reaches exactly n, return true. Otherwise, if pwr exceeds n, return false.

T.C: O(log n)
S.C: O(1)
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
       long long pwr = 1;
       if (pwr > n) return false;
       while (pwr <= n){
        if (pwr == n) return true;
        pwr = pwr * 2;
       } 
       return false;
    }
};

/*
Approach 3: Bitwise Trick (Optimal)
A positive power of 2 has exactly one set bit in its binary representation.
Subtracting 1 flips all bits after the set bit.
Therefore, n & (n - 1) will equal 0 if and only if n is a power of 2.

T.C: O(1)
S.C: O(1)
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};
