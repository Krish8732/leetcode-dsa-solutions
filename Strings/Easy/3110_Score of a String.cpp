// LeetCode: https://leetcode.com/problems/score-of-a-string/
// Concepts: String, Iteration

/*
Intuition:
The score of a string is defined as the sum of the absolute differences between the ASCII values of adjacent characters.

Iterate through the string from index 0 to s.size() - 2, compute `|ASCII(s[i]) - ASCII(s[i+1])|`, and accumulate the sum.

T.C: O(N) where N is the length of string s.
S.C: O(1) space.
*/

class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;
        for (int i = 0; i<s.size()-1; i++){
           int c1 = (int)s[i];
           int c2 = (int)s[i+1];
           int diff = abs(c1-c2); 
           sum += diff;
        }
        return sum;
    }
};
