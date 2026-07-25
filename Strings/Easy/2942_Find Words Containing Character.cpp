// LeetCode: https://leetcode.com/problems/find-words-containing-character/
// Concepts: Array, String, Searching, C++ STL

/*
Intuition:
We are given an array of strings `words` and a character `x`.
We need to return an array of indices representing the words that contain the character `x`.

Approach 1: Nested Loops / Manual Search
Iterate through each word at index `i`, check characters manually, and push `i` to `res` as soon as `x` is found.
T.C: O(N * M) where N is number of words and M is maximum word length.
S.C: O(1) auxiliary space.

Approach 2: Concise C++ STL (using string::find)
Use `words[i].find(x) != string::npos` to quickly check if `x` exists in `words[i]`.
T.C: O(N * M)
S.C: O(1) auxiliary space.
*/

// Approach 1: Nested Loops Search
class SolutionLoops {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                if (words[i][j] == x) {
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};

// Approach 2: Concise C++ STL (using string::find)
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        for (int i = 0; i < words.size(); i++) {
            if (words[i].find(x) != string::npos) {
                res.push_back(i);
            }
        }
        return res;
    }
};
