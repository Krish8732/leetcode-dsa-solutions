// LeetCode: https://leetcode.com/problems/count-symmetric-integers/
// Concepts: Math, String, Enumeration

/*
Intuition:
An integer `x` is symmetric if:
1. It has an even number of digits `2 * k`.
2. The sum of the first `k` digits is equal to the sum of the last `k` digits.

We iterate through each number `x` from `low` to `high`, convert it to string, check if its length `n` is even, and compare the sum of the first half of digits with the second half.

T.C: O((high - low + 1) * log10(high))
S.C: O(log10(high)) space for string representation.
*/

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        auto f = [](int x) {
            string s = to_string(x);
            int n = s.size();
            if (n & 1) {
                return 0;
            }
            int a = 0, b = 0;
            for (int i = 0; i < n / 2; ++i) {
                a += s[i] - '0';
                b += s[n / 2 + i] - '0';
            }
            return a == b ? 1 : 0;
        };
        for (int x = low; x <= high; ++x) {
            ans += f(x);
        }
        return ans;
    }
};
