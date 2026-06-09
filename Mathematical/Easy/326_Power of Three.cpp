// LeetCode: https://leetcode.com/problems/power-of-three/
// Concepts: Math

// Approach 1 (Largest Power of 3): 3^19 = 1162261467 is the largest power of 3 that fits in a 32-bit int. If n is a power of 3, it must divide 1162261467 evenly.
// TC: O(1) | SC: O(1)

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0)
            return false;
        return 1162261467 % n == 0;
    }
};

// Approach 2 (Iterative Division): Keep dividing n by 3 as long as it's divisible. If the final result is 1, n was a power of 3.
// TC: O(log3 n) | SC: O(1)

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
