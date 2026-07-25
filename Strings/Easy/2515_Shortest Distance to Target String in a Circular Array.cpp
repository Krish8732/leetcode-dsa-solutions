// LeetCode: https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/
// Concepts: Array, String, Circular Array

/*
Intuition:
We are given a circular array of strings `words`, a `target` string, and a `startIndex`.
We can move left or right one step at a time (wrapping around the ends of the array).
We need to find the shortest distance from `startIndex` to any occurrence of `target`.

In a circular array of size `n`:
- The direct distance between `startIndex` and index `i` is `dist = |startIndex - i|`.
- The reverse circular distance going around the boundary is `revDist = n - dist`.
- The shortest distance to reach index `i` is `min(dist, revDist)`.

Iterate through `words`, and whenever `words[i] == target`, compute `min(dist, n - dist)` and track the global minimum. If `target` is not found, return -1.

T.C: O(N * M) where N is length of words and M is average length of string.
S.C: O(1) auxiliary space.
*/

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int minDist = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int dist = abs(startIndex - i);
                int revDist = n - dist;
                minDist = min(minDist, min(dist, revDist));
            }
        }

        return minDist == INT_MAX ? -1 : minDist;
    }
};
