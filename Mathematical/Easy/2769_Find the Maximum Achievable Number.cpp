// LeetCode: https://leetcode.com/problems/find-the-maximum-achievable-number/
// Concepts: Math

/*
Intuition:
An integer `x` is achievable if it can become equal to `num` after applying the following operation at most `t` times:
- Increase or decrease `x` by 1, AND simultaneously increase or decrease `num` by 1.

To maximize `x`:
In each of the `t` operations:
- Decrease `x` by 1 and increase `num` by 1.
- Net effect per step: `x - 1 = num + 1` => `x = num + 2`.
After `t` steps: `x = num + 2 * t`.

T.C: O(1)
S.C: O(1)
*/

class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        return num + (2 * t);
    }
};
