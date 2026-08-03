// LeetCode: https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
// Concepts: Array, Two Pointers, String

/*
Intuition:
Use two pointers for array indices (`i` and `j`) and two pointers for character indices (`p1` and `p2`) within the current strings of `word1` and `word2`. Compare characters step-by-step without concatenating the strings.

T.C: O(N) where N is the total number of characters across all strings in word1 / word2.
S.C: O(1) auxiliary space.
*/

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, j = 0;
        int p1 = 0, p2 = 0;

        while (i < word1.size() && j < word2.size()) {
            if (word1[i][p1] != word2[j][p2])
                return false;
            p1++, p2++;
            if (p1 == word1[i].size()) {
                i++, p1 = 0;
            }
            if (p2 == word2[j].size()) {
                j++, p2 = 0;
            }
        }
        return (i == word1.size() && j == word2.size());
    }
};
