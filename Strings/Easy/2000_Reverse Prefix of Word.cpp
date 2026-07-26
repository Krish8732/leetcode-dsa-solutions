// LeetCode: https://leetcode.com/problems/reverse-prefix-of-word/
// Concepts: Two Pointers, String

/*
Intuition:
Find the first occurrence of character `ch` in `word`.
If found at index `idx`, reverse the segment from index `0` to `idx` inclusive using `reverse()`.
If `ch` does not exist in `word`, return `word` unchanged.

T.C: O(N) where N is the length of `word`.
S.C: O(1) auxiliary space (in-place modification).
*/

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx = -1;
        int i = 0;
        for (i = 0; i < word.size(); i++) {
            if (word[i] == ch) {
                idx = i;
                break;
            }
        }
            if (idx != -1) {
                reverse(word.begin(), word.begin() + i + 1);
            }
            return word;
    }
};
