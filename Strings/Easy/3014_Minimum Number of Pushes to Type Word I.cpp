// LeetCode: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/
// Concepts: String, Greedy, Math

/*
Intuition:
We are given a string `word` consisting of distinct lowercase English letters. We need to map these letters to keys 2 through 9 (8 keys total) to minimize total key pushes.
Since all characters in `word` are distinct:
- The first 8 letters can be assigned as the 1st character on each of the 8 keys (1 push each).
- The next 8 letters (indices 8 to 15) can be assigned as the 2nd character on each key (2 pushes each).
- The next 8 letters (indices 16 to 23) can be assigned as the 3rd character on each key (3 pushes each).
- Any remaining letters require 4 pushes each.

T.C: O(N) where N is the length of `word`.
S.C: O(1) auxiliary space.
*/

class Solution {
public:
    int minimumPushes(string word) {
        int cnt = 0;
        for (int i = 0; i < word.size(); i++) {
            if (i < 8)
                cnt += 1;
            else if (i < 16)
                cnt += 2;
            else if (i < 24)
                cnt += 3;
            else
                cnt += 4;
        }

        return cnt;
    }
};
