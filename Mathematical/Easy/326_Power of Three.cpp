// Leetcode: https://leetcode.com/problems/power-of-three/
// Concepts: Math, Recursion

/*
Approach 1: Max 32-Bit Power of 3 Modulo (O(1) Math)
Intuition:
The maximum power of 3 that fits within a signed 32-bit integer is 3^19 = 1162261467.
Since 3 is a prime number, the only divisors of 3^19 are smaller powers of 3 (3^0, 3^1, ..., 3^19).
Therefore, n is a power of 3 if and only if n > 0 and 1162261467 % n == 0.

T.C: O(1)
S.C: O(1)
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0)
            return false;
        return 1162261467 % n == 0;
    }
};

/*
Approach 2: Iterative Division (Active Solution)
Intuition:
If n is a power of 3, its prime factorization contains only 3s.
Repeatedly divide n by 3 as long as n is divisible by 3.
If n reduces to 1, it was a power of 3.

T.C: O(log3 n)
S.C: O(1)
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0)
            return false;

        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};

/*
Approach 3: Iterative Multiplication
Intuition:
Start at 1 (3^0) and repeatedly multiply by 3 as long as pwr <= n.
If pwr equals n, return true.

T.C: O(log3 n) - Same as Approach 2
S.C: O(1)      - Same as Approach 2
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        long long pwr = 1;
        while (pwr < n) {
            pwr *= 3;
        }
        return pwr == n;
    }
};
