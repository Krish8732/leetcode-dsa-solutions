// LeetCode: https://leetcode.com/problems/minimum-common-value/
// Concepts: Array, Two Pointers, Binary Search

/*
Intuition:
Given two integer arrays `nums1` and `nums2`, sorted in non-decreasing order, return the minimum integer common to both arrays.
If there is no common integer, return -1.

Since both arrays are already sorted, we can use a two-pointer approach:
1. Initialize pointer `i = 0` for `nums1` and `j = 0` for `nums2`.
2. Compare `nums1[i]` and `nums2[j]`:
   - If `nums1[i] == nums2[j]`, return `nums1[i]` (smallest common value).
   - If `nums1[i] > nums2[j]`, increment `j++`.
   - If `nums1[i] < nums2[j]`, increment `i++`.
3. If loop finishes without match, return -1.

T.C: O(M + N) where M is length of nums1 and N is length of nums2.
S.C: O(1) auxiliary space.
*/

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] == nums2[j])
                return nums1[i];
            else if (nums1[i] > nums2[j])
                j++;
            else
                i++;
        }

        return -1;
    }
};
