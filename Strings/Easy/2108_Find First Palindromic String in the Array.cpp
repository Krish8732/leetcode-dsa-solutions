// LeetCode: https://leetcode.com/problems/find-first-palindromic-string-in-the-array/
// Concepts: Array, Two Pointers, String

/*
Intuition:
Iterate through the array of strings and check if each string is equal to its reverse.
Return the first string that satisfies the palindrome condition. If no palindromic string is found, return an empty string.

Note: We can also use the two-pointer approach to check if a string is a palindrome in O(1) extra space.

T.C: O(N * M) where N is the number of words and M is the maximum length of a string.
S.C: O(M) space for constructing the reversed string.
*/

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (string s : words) {
            if ( s == string(s.rbegin(), s.rend())){
                return s;
            }
        }
        return "";
    }
};
