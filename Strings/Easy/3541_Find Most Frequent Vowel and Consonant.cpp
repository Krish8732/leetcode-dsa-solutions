// LeetCode: https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/
// Concepts: Strings, Hash Table, Frequency Counting

/*
Intuition:
We need to find the sum of the maximum frequency of any vowel ('a', 'e', 'i', 'o', 'u') and the maximum frequency of any consonant in `s`.

1. Count occurrences of each character in a frequency array `arr` of size 26.
2. Iterate through `arr[0...25]`. If character `'a' + i` is in `"aeiou"`, update `maxV` (maximum vowel frequency), else update `maxC` (maximum consonant frequency).
3. Return `maxC + maxV`.

T.C: O(N) where N is length of string `s`.
S.C: O(1) space for 26-element array.
*/

class Solution {
public:
    int maxFreqSum(string s) {
        int maxC = 0;
        int maxV = 0;
        int arr[26] = {0};
        string vowels = "aeiou";
        for ( char c : s ){
                int cnt = c - 'a';
                arr[cnt]++;
        }

        for ( int i = 0; i < 26; i++){
            char ch = 'a' + i;
            if ( vowels.find(ch) != string::npos ){
                maxV = max(maxV, arr[i]);
            }
            else maxC = max(maxC, arr[i]);
        }

        return maxC + maxV;
    }
};
