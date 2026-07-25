// LeetCode: https://leetcode.com/problems/count-the-digits-that-divide-a-number/
// Concepts: Math, Digit Extraction

/*
Intuition:
Given an integer `num`, return the number of digits in `num` that divide `num`.
Every digit in `num` is guaranteed to be non-zero.

1. Copy `num` to `temp`.
2. Extract each digit `n = temp % 10`.
3. Check if `num % n == 0`. If true, increment `cnt`.
4. Divide `temp /= 10` until `temp == 0`.
5. Return `cnt`.

T.C: O(log10(num))
S.C: O(1) auxiliary space.
*/

class Solution {
public:
    int countDigits(int num) {
        int temp = num;
        int cnt = 0;
        while (temp > 0) {
            int n = temp % 10;
            if (num % n == 0)
                cnt++;
            temp /= 10;
        }
        return cnt;
    }
};
