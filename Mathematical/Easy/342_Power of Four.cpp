// Leetcode: https://leetcode.com/problems/power-of-four/
// Concepts: Math, Bit Manipulation

/*
Approach 1: Iterative Multiplication
Intuition:
Start at 1 (4^0) and continuously multiply by 4 while pwr <= n.
If pwr reaches n, return true.

T.C: O(log4 n)
S.C: O(1)
*/

class Solution {
public:
    bool isPowerOfFour(int n) {
        long long pwr = 1;
        if (n <= 0)
            return false;
        while (pwr <= n) {
            if (pwr == n)
                return true;
            pwr = pwr * 4;
        }
        return false;
    }
};

/*
Approach 2: Logarithm
Intuition:
Calculate x = log(n) / log(4). Check if 4^x equals n.

T.C: O(1)
S.C: O(1)
*/

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;

        int x = log(n) / log(4);

        return pow(4, x) == n;
    }
};

/*
Approach 3: Bitwise & Math Trick (Optimal)
Intuition:
A number is a power of 4 if:
1. It is a power of 2: (n & (n - 1)) == 0.
2. (4^k - 1) is always a multiple of 3: (n - 1) % 3 == 0.
Powers of 2 that are NOT powers of 4 (like 2, 8, 32) do not satisfy (n - 1) % 3 == 0.

T.C: O(1)
S.C: O(1)
*/

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return 0;

        return (((n - 1) % 3 == 0) && ((n & (n-1)) == 0));
    }
};
