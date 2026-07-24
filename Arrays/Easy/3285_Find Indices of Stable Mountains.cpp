// LeetCode: https://leetcode.com/problems/find-indices-of-stable-mountains/
// Concepts: Array, Simulation

/*
Intuition:
A mountain at index `i` (for `i > 0`) is considered stable if the mountain immediately to its left (`height[i-1]`) has height strictly greater than `threshold`.

Iterate from index `n-1` down to 1. If `height[i-1] > threshold`, add index `i` to the result vector.

T.C: O(N)
S.C: O(1) auxiliary space (excluding result vector)
*/

class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        int n = height.size();
        vector<int> res;
        for ( int i = n-1; i>0; i-- ){
            if ( height[i-1] > threshold ){
                res.push_back(i);
            }
        }
        return res;
    }
};
