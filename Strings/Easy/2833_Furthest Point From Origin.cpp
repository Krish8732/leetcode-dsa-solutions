// LeetCode: https://leetcode.com/problems/furthest-point-from-origin/
// Concepts: String, Counting, Greedy

/*
Intuition:
We are given a string `moves` consisting of characters 'L', 'R', and '_'.
- 'L' moves us 1 step to the left (-1).
- 'R' moves us 1 step to the right (+1).
- '_' can be chosen to move either left (-1) or right (+1).

To maximize the furthest distance from origin (0):
1. Count 'L' moves (`lCnt`), 'R' moves (`rCnt`), and wildcard '_' moves (`anyCnt`).
2. Net displacement without wildcards is `|lCnt - rCnt|`.
3. Direct all wildcard moves in whichever direction expands the displacement.
4. Total maximum distance is `|lCnt - rCnt| + anyCnt`.

T.C: O(N) where N is length of moves.
S.C: O(1) auxiliary space.
*/

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int lCnt = 0;
        int rCnt = 0;
        int anyCnt = 0;
        for (char c : moves) {
            if (c == 'L')
                lCnt++;
            else if (c == 'R') 
                rCnt++;
            else
                anyCnt++;
        }

        return abs(lCnt - rCnt) + anyCnt;
    }
};
