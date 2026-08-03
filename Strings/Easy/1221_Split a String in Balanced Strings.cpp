// LeetCode: https://leetcode.com/problems/split-a-string-in-balanced-strings/
// Concepts: String, Greedy, Counting

/*
Intuition:
We should add to our count only when both counts (cntL and cntR) are equal and non-zero, then reset them. We don't need to worry about what comes after we reset because it will be guaranteed different than the current state when both counts were equal, so we won't miss any cases.

Time Complexity: O(N) where N is the length of the string s.
Space Complexity: O(1) auxiliary space.
*/

class Solution {
public:
    int balancedStringSplit(string s) {
        int cnt = 0;
        int cntR = 0;
        int cntL = 0;
        for (char c : s) {
            if (c == 'L')
                cntL++;
            if (c == 'R')
                cntR++;
            if (cntL != 0 && cntR != 0 && cntL == cntR) {
                cnt++;
                cntL = 0, cntR = 0;
            }
        }
        return cnt;
    }
};
