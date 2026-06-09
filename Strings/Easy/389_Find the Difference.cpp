// LeetCode: https://leetcode.com/problems/find-the-difference/
// Concepts: String, Sorting, Hash Table, Bit Manipulation

// Approach 1 (Sorting): Sort both strings and compare character by character. The first mismatch is the added character.
// TC: O(n log n) | SC: O(1)

class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for ( int i = 0; i < s.size(); i++ ){
            if ( s[i] != t[i] ) return t[i];
        }
        return t[t.size()-1];
    }
};

// Approach 2 (ASCII Sum): Compute the sum of ASCII values of characters in t and subtract the sum of ASCII values of characters in s. The difference is the added character.
// TC: O(n) | SC: O(1)

class Solution {
public:
    char findTheDifference(string s, string t) {
        int asciiSum = 0;
        for (char c : t) asciiSum += c; //can use % 256 if input is very large
        for (char c : s) asciiSum -= c;
        return (char)asciiSum;
    }
};

// Approach 3 (Bit Manipulation - XOR): XOR all characters of both strings. Matching characters will cancel out (x ^ x = 0), leaving only the extra character.
// TC: O(n) | SC: O(1)

class Solution {
public:
    char findTheDifference(string s, string t) {
        char result = 0;
        for (char c : s) result ^= c;
        for (char c : t) result ^= c;
        return result;
    }
};
