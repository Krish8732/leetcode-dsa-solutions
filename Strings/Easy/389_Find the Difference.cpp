// Leetcode: https://leetcode.com/problems/find-the-difference/
// Concepts: String, Hash Table, Bit Manipulation, Sorting

/*
Approach 1: Sorting
Sort both strings and compare character by character. The first mismatch is the added character.

T.C: O(n log n)
S.C: O(1)
*/

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

/*
Approach 2: ASCII Sum Difference (Optimal)
Intuition:
Compute the sum of ASCII values of all characters in string t and subtract the sum of 
ASCII values of all characters in string s. The remaining difference is the added character.

T.C: O(n)
S.C: O(1)
*/

class Solution {
public:
    char findTheDifference(string s, string t) {
        int asciiSum = 0;
        for (char c : t)
            asciiSum += c; // can use % 256 if input is very large
        for (char c : s)
            asciiSum -= c;
        return (char)asciiSum;
    }
};

/*
Approach 3: Bit Manipulation (XOR Trick)
Intuition:
We can also use the XOR trick to find the extra character due to XOR properties:
x ^ x = 0 (matching characters cancel out) and x ^ 0 = x.
XORing all characters of both s and t will cancel out every matching pair, leaving only the extra character.

T.C: O(n)
S.C: O(1)
*/

class Solution {
public:
    char findTheDifference(string s, string t) {
        char result = 0;
        for (char c : s) result ^= c;
        for (char c : t) result ^= c;
        return result;
    }
};
