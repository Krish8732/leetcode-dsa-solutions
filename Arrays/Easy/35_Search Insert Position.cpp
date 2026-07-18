// LeetCode: https://leetcode.com/problems/search-insert-position/
// Concepts: Array, Binary Search

// Approach 1 (Binary Search - Lower Bound style): Binary search the lower bound of target. `ans` stores the first index where `nums[mid] >= target`. If no such element exists, it remains `n`.
// TC: O(log n) | SC: O(1)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = n;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] >= target) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }
};

// Approach 2 (Standard Binary Search): Standard binary search. If the target is found, return the index `mid`. If the search ends without finding target, `l` (low pointer) points to the position where the target should be inserted.
// TC: O(log n) | SC: O(1)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int curr = nums[mid];
            if (curr == target)
                return mid;
            else if (curr < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return l;
    }
};
