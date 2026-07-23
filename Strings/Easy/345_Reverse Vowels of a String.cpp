// Leetcode: https://leetcode.com/problems/reverse-vowels-of-a-string/
// Concepts: Two Pointers, String

/*
Intuition:
Use two pointers (i at start, j at end).
Advance i forward until a vowel is found, and move j backward until a vowel is found.
Swap the vowels at i and j, then advance both pointers. Repeat until i and j cross.

T.C: O(n)
S.C: O(1)
*/

class Solution {
public:
    static bool isVowel(char c){
        c = tolower(static_cast<unsigned char>(c));
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;
        while(i<j){
            while (i<j && !isVowel(s[i])) i++;
            while (i<j && !isVowel(s[j])) j--;

            if (i<j){
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};
