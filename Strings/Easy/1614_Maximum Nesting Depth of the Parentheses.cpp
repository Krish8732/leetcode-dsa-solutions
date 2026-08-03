// LeetCode: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
// Concepts: String, Stack

/*
Intuition:
Track the current depth of open parentheses '(' using a counter variable `depth`. Increment `depth` on encounter of '(' and update `maxid`, and decrement `depth` on encounter of ')'. Ignore non-parenthesis characters.

T.C: O(N) where N is the length of string `s`.
S.C: O(1) auxiliary space.
*/

class Solution {
public:
    int maxDepth(string s) {
        int maxid = 0;
        int depth = 0;
        for (char c : s ){
            if ( c == '(' ){
                depth++;
                maxid = max(maxid, depth);
            }
            else if ( c == ')' ){
                depth--;
            }
        }
        return maxid;
    }
};
