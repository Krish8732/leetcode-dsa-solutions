// LeetCode: https://leetcode.com/problems/maximum-number-of-words-you-can-type/
// Concepts: Hash Table, String

/*
Approach 1: Direct Scanning / Brute Force Comparison
Intuition:
Iterate through each character of text. For each character, check if it exists in brokenLetters.
If a broken letter is found, mark the word as untypable and skip the rest of the current word.
Increment count when a valid typable word ends.

T.C: O(N * M) where N is length of text and M is length of brokenLetters
S.C: O(1)
*/

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int cnt = 0;
        bool canType = true;
        int i = 0;
        while (i < text.size()) {
            for (int j = 0; j < brokenLetters.size(); j++) {
                if (text[i] == brokenLetters[j]) {
                    canType = false;
                    break;
                }
            }
            if (canType == false) {
                while (text[i] != ' ' && i < text.size())
                    i++;
            }

            if (text[i] == ' ' || i == text.size() - 1) {
                if (canType == true) cnt++;
                canType = true;
            }
            i++;
        }
        return cnt;
    }
};

/*
Approach 2: Hash Set / Frequency Array Lookup (Optimal)
Intuition:
Store the broken letters in a boolean array of size 26 for O(1) lookup.
Traverse the string text and check if any character in the word is broken. If broken, skip to the end of the word.
Maintain count of fully typable words.

T.C: O(N + M) where N is length of text and M is length of brokenLetters
S.C: O(1) auxiliary space (boolean array of size 26)
*/

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> broken(26, 0);

        for (char c : brokenLetters) {
            broken[c - 'a'] = true;
        }

        bool endWord = true;

        int i = 0;
        int n = text.size();
        int cnt = 0;

        while (i < n) {

            if (endWord && text[i] == ' ') {
                cnt++;
                i++;
                continue;
            }
            if (broken[text[i] - 'a']) {
                endWord = false;
                while (i < n && text[i] != ' ')
                    i++;
            }
            if (text[i] == ' ' && !endWord)
                endWord = true;
            i++;
        }

        cnt += endWord;

        return cnt;
    }
};
