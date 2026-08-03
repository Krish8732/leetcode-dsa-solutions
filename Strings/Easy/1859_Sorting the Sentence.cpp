// LeetCode: https://leetcode.com/problems/sorting-the-sentence/
// Concepts: String, Stream, Sorting, Two Pointers

/*
Approach 1 (Stream Extraction - Clean):
Use `std::stringstream` to extract space-separated words from string `s`.
For each word, extract its 1-based target position (`word.back() - '0'`), remove the digit using `word.pop_back()`, and store the word in a fixed-size `vector<string> words(10)`. Finally, iterate from index 1 to 9, concatenate words with space delimiter, and trim trailing space.

T.C: O(N) where N is the length of `s`.
S.C: O(N) for extracted words and result string.

Approach 2 (Direct Index Scanning & Substring Extraction):
Iterate through characters of `s`. Whenever a digit character (1-9) is encountered, slice the word starting from `startPos` up to the current index using `s.substr(startPos, i - startPos)` and place it into `vec[s[i] - '0']`. Advance `startPos` past the digit and space to `i + 2`.

T.C: O(N) where N is the length of `s`.
S.C: O(N) for string storage and result string.
*/

class Solution {
public:
    // Approach 1: std::stringstream Parsing
    string sortSentence(string s) {
        stringstream ss(s);
        string word;
        vector<string> words(10);

        while (ss >> word) {
            int pos = word.back() - '0';
            word.pop_back();
            words[pos] = word;
        }

        string result = "";
        for (int i = 1; i < 10 && !words[i].empty(); i++) {
            result += words[i] + " ";
        }
        result.pop_back();

        return result;
    }

    // Approach 2: Direct Scanning & Substring Extraction
    string sortSentenceDirectScan(string s) {
        int n = s.size();

        vector<string> vec(10);
        int startPos = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] - '0' > 0 && s[i] - '0' < 10) {
                vec[s[i] - '0'] = s.substr(startPos, i - startPos);
                startPos = i + 2;
            }
        }

        string result = "";

        for (int i = 1; i < 10; i++) {
            if (vec[i] == "")
                break;
            result += vec[i] + " ";
        }
        result.pop_back();

        return result;
    }
};
