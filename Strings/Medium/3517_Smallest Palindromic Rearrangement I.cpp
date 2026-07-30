// LeetCode: https://leetcode.com/problems/smallest-palindromic-rearrangement-i/
// Concepts: String, Sorting, Greedy

/*
Intuition:
We are given a palindromic string `s` and want to find the lexicographically smallest palindromic rearrangement.
Because `s` is already guaranteed to be a palindrome:
1. Sorting the first half `s[0 ... mid-1]` places the smallest available characters at the beginning.
2. Mirroring the sorted first half to the second half `s[n-1-i] = s[i]` ensures the string remains a valid palindrome while forming the smallest lexicographical arrangement.

T.C: O(N log N) where N is the length of `s` (due to sorting the first half of size N/2).
S.C: O(1) auxiliary space (in-place rearrangement).
*/

class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();

        int mid = n / 2;
        sort(s.begin(), s.begin() + mid);

        for (int i = 0; i < mid; i++) {
            s[n - 1 - i] = s[i];
        }

        return s;
    }
};
