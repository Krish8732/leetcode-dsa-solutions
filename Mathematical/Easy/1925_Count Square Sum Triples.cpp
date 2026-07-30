// LeetCode: https://leetcode.com/problems/count-square-sum-triples/
// Concepts: Math, Brute Force, Two Pointers

/*
Intuition:
We need to count all triples (a, b, c) where a^2 + b^2 = c^2 and 1 <= a, b, c <= n.
Note: (a, b, c) and (b, a, c) are counted as distinct triples.

Approach:
- Iterate over all pairs (i, j) where i < j to avoid counting symmetric duplicates.
- For each pair, compute sum = i^2 + j^2 and check if sqrt(sum) is a perfect integer <= n.
- Since (i, j, c) and (j, i, c) are both valid, multiply each valid find by 2.

T.C: O(N^2) where N is the given input value (nested loops over all valid pairs).
S.C: O(1) auxiliary space.
*/

class Solution {
public:
    int countTriples(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int sum = i * i + j * j;
                int c = sqrt(sum);
                if (c * c == sum && c <= n) {
                    count += 2;
                }
            }
        }
        return count;
    }
};
