// LeetCode: https://leetcode.com/problems/sort-colors/
// Concepts: Array, Two Pointers, Sorting

/*
Approach 1 (Dutch National Flag Algorithm): Use three pointers (low, mid, high) to maintain 4 partitions:
  - [0 ... low-1]   -> Sorted 0s
  - [low ... mid-1]  -> Sorted 1s
  - [mid ... high]   -> Unexplored elements
  - [high+1 ... n-1] -> Sorted 2s

Since mid scans left-to-right, any 2 is swapped to high (which decrements). Thus, no 2 can exist behind mid.
Consequently, nums[low] is guaranteed to be 1 (if low < mid) or 0 (if low == mid) when swapping with nums[mid] == 0.

TC: O(N) | SC: O(1)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                low++, mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                 high--;
            }
        }
    }
};
