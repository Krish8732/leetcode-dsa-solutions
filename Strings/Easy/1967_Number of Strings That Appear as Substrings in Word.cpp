// LeetCode: https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/
// Concepts: Array, String, Substring Search

/*
Intuition:
Brute-force manual string matching without using `std::string::find`. For each pattern `p` in `patterns`, iterate through `word` using pointers `i` (for `p`) and `j` (for `word`). Search from every start point in `word`; if matching fails, reset matching and retry starting from the next character (`lastPos + 1`). If `i` reaches `n`, the pattern exists as a substring.

T.C: O(K * N * M) where K is number of patterns, N is pattern length, and M is length of word.
S.C: O(1) auxiliary space.
*/

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;
        for (auto& p : patterns) {
            int i = 0, j = 0;
            int n = p.size(), m = word.size();
            bool started = 0;
            int lastPos = 0;
            while (i < n && j < m) {
                char a = p[i], b = word[j];
                if (!started && a == b) {
                    started = true;
                    i++, j++;
                } else if (!started && a != b) {
                    j++;
                    lastPos++;
                } else if (started && a == b) {
                    i++, j++;
                } else {
                    i = 0, j = lastPos + 1, started = 0, lastPos++;
                }
            }

            cnt += (i == n) ? 1 : 0;
        }

        return cnt;
    }
};
