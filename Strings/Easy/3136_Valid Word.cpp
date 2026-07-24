// LeetCode: https://leetcode.com/problems/valid-word/
// Concepts: String, Counting

/*
Intuition:
A word is valid if:
1. It contains at least 3 characters.
2. It consists only of alphanumeric characters (digits and English letters).
3. It contains at least one vowel ('a', 'e', 'i', 'o', 'u' case-insensitive).
4. It contains at least one consonant (any English letter that is not a vowel).

Iterate through each character of the string and validate these conditions.

T.C: O(N) where N is the length of word.
S.C: O(1) auxiliary space.
*/

class Solution {
public:
    bool isValid(string word) {
        if (word.length() < 3)
            return false;
        bool hasVowel = false;
        bool hasConsonant = false;
        for (int i = 0; i < word.length(); i++) {
            char c = word[i];
            if (!isalnum(c)) {
                return false;
            }
            if (isalpha(c)) {
                char lower = tolower(c);

                if (lower == 'a' || lower == 'e' || lower == 'i' ||
                    lower == 'o' || lower == 'u') {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            }
        }
        return hasVowel && hasConsonant;
    }
};
