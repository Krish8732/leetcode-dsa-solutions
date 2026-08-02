// LeetCode: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
// Concepts: Array

/*
Intuition & Explanation:
- In a sorted and rotated array, elements are non-decreasing except at possibly one point (the rotation pivot), where an element is strictly greater than the next element: `nums[i] > nums[(i + 1) % n]`.
- Using modulo `% n` allows us to cleanly compare the last element `nums[n-1]` with the first element `nums[0]` as part of the circular check.
- If the array is sorted and rotated, this decreasing transition ("drop" or "peak break") can occur at most once (`peak <= 1`).
- If such a drop occurs more than once (`peak > 1`), the array could not have been formed by rotating a sorted array, so we return `false`.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int peak = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n])
                peak++;
        }

        return peak <= 1;
    }
};
