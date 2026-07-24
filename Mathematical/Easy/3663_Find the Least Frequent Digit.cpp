// LeetCode: https://leetcode.com/problems/find-the-least-frequent-digit/
// Concepts: Math, Hash Table, Frequency Counting

/*
Intuition:
We need to find the least frequent digit in the decimal representation of `n`. If there is a tie, return the smallest digit.

1. Maintain a frequency array `digitCount` of size 10 initialized to 0.
2. Extract digits of `n` using modulo 10 and increment their count in `digitCount`.
3. Find the minimum non-zero frequency `minFreq` among all digits 0-9.
4. Iterate from 0 to 9 to find the first digit matching `minFreq` (ensuring smallest digit on tie).

T.C: O(log10(n))
S.C: O(1)
*/

class Solution {
public:
    int getLeastFrequentDigit(int n) {
        int digitCount[10] = {0};
        
        while (n > 0) {
            int digit = n % 10;
            digitCount[digit]++;
            n /= 10;
        }
        
        int minFreq = INT_MAX;
        for (int i = 0; i < 10; i++) {
            if (digitCount[i] > 0 && digitCount[i] < minFreq) {
                minFreq = digitCount[i];
            }
        }
        
        for (int i = 0; i < 10; i++) {
            if (digitCount[i] == minFreq) {
                return i;
            }
        }
        
        return -1; 
    }
};
