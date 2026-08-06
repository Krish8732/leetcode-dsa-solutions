// LeetCode: https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/
// Concepts: Math

// Approach (Iterative Check):
// Intuition:
// We need to find two integers a and b such that a + b = n and neither a nor b contains the digit 0.
// We can start with a = 1 and b = n - 1, and check if both have no zeroes.
// If either has a zero, we increment a and decrement b, and repeat the check.
// Since a valid pair is guaranteed to exist for all n in the range [2, 10000], this simple search will terminate quickly.
// TC: O(n log10(n)) in the worst case (usually much faster) | SC: O(1)

class Solution {
    bool hasZeroes(int n) {
        while (n > 0) {
            if (n % 10 == 0)
                return true;
            n = n / 10;
        }
        return false;
    }

public:
    vector<int> getNoZeroIntegers(int n) {
        int a = 1;
        int b = n - 1;
        while (hasZeroes(a) || hasZeroes(b)) {
            a++;
            b--;
        }
        return {a, b};
    }
};
