// LeetCode: https://leetcode.com/problems/count-the-number-of-special-characters-i/
// Concepts: String, Hash Table, Frequency Array

/*
Intuition:
A character is "special" if both its lowercase and uppercase forms appear in `word`.

1. Count the frequencies of each character using an ASCII array `arr` of size 123.
2. Iterate through uppercase ASCII letters 'A' to 'Z' (65 to 90).
3. Check if both uppercase character 'A'+i and its lowercase counterpart 'a'+i (which is ASCII + 32) have count > 0.
4. Increment result if both exist.

T.C: O(N) where N is the length of word.
S.C: O(1) space using a fixed size frequency array.
*/

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int arr[123] = {0};
        int n = word.size();

        for (char c : word) {
            arr[c]++;
        }

        int res = 0;

        for (int i = 65; i <= 90; i++) {
            int capIdx = i + 32;
            if (arr[i] > 0 && arr[capIdx] > 0)
                res++;
        }

        return res;
    }
};
