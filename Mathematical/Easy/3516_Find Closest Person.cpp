// LeetCode: https://leetcode.com/problems/find-closest-person/
// Concepts: Math

/*
Intuition:
We are given positions x, y, and target position z. We compute absolute distances `diff1 = abs(x - z)` and `diff2 = abs(y - z)`.
- If `diff1 < diff2`, Person 1 is closer (return 1).
- If `diff1 > diff2`, Person 2 is closer (return 2).
- If `diff1 == diff2`, both are equidistant (return 0).

T.C: O(1)
S.C: O(1)
*/

class Solution {
public:
    int findClosest(int x, int y, int z) {
        int diff1 = abs(x-z);
        int diff2 = abs(y-z);
        if ( diff1 < diff2) return 1;
        else if ( diff1 > diff2) return 2;
        else return 0;
    }
};
