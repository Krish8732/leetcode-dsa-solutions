// LeetCode: https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/
// Concepts: String, Greedy

// Approach (Count Flips for Both Alternatives):
// Intuition:
// An alternating binary string can only start with '0' or '1'.
// Case 1: The alternating string starts with '0' (e.g., "010101...").
// Case 2: The alternating string starts with '1' (e.g., "101010...").
// We can compute the number of operations/flips needed to transform s into both styles.
// Since one is the exact inverse of the other, if we need `k` flips to reach the "0101..." pattern,
// we will need `n - k` flips to reach the "1010..." pattern.
// We can count the operations for one pattern, say starting with '0', and return min(flips, n - flips).
// TC: O(n) | SC: O(1)

class Solution {
public:
    int minOperations(string s) {
        int zeroStart = 0; // operations needed to make pattern starting with '0'
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                // For '010101...', even indexes should be '0'
                if (s[i] != '0') {
                    zeroStart++;
                }
            } else {
                // Odd indexes should be '1'
                if (s[i] != '1') {
                    zeroStart++;
                }
            }
        }
        return min(zeroStart, n - zeroStart);
    }
};
