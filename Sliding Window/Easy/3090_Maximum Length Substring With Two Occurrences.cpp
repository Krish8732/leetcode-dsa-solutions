// LeetCode: https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/
// Concepts: String, Sliding Window, Hash Table

/*
Intuition:
We want to find the maximum length of a substring such that no character appears more than 2 times.

Approach:
1. Brute force approach: Try all substrings, which would take O(N^2) or similar.
2. Optimized (Sliding Window): Use a classic two-pointer sliding window approach. Expand `j` to include characters, updating character counts. If any character count exceeds 2, shrink the window from the left using `i` until valid. Update `maxLen` at each iteration of `j`.

T.C: O(2N) = O(N) at worst case as each character is processed at most twice (once by j, once by i).
S.C: O(1) auxiliary space (fixed array of size 26 for alphabet frequencies).
*/

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int arr[26] = {0};
        int maxLen = 1;

        int i = 0, j = 0;
        while (j < n) {
            int curr = s[j] - 'a';
            arr[curr]++;

            while (arr[curr] > 2) {
                arr[s[i] - 'a']--;
                i++;
            }

            maxLen = max(maxLen, j - i + 1);

            j++;
        }

        return maxLen;
    }
};
