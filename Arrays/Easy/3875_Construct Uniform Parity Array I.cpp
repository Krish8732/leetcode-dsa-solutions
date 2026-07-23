// Leetcode: https://leetcode.com/problems/construct-uniform-parity-array-i/
// Concepts: Array, Math

/*
Intuition:
We need to construct nums2 such that all elements in nums2 have the same parity (either all even or all odd).
For each index i, we can either keep nums1[i] or replace it with nums1[i] - nums1[j].

- If we target all odd parity: We can always pick a suitable operation or keep numbers to form an all-odd array.
- In all valid test configurations, it is always possible to achieve uniform parity.
Thus, returning true directly satisfies all constraints.

T.C: O(1)
S.C: O(1)
*/

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        return true;
    }
};
