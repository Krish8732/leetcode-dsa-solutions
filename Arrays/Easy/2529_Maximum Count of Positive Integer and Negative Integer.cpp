// LeetCode: https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/
// Concepts: Array, Binary Search, Counting

/*
Intuition:
Given an array `nums` sorted in non-decreasing order, return the maximum between the count of positive integers and the count of negative integers (0 is neither positive nor negative).

Approach 1: Linear Scan
Iterate through `nums` and count positive numbers (`pc`) and negative numbers (`nc`).
T.C: O(N)
S.C: O(1)

Approach 2: Optimal Binary Search (std::lower_bound & std::upper_bound)
Since `nums` is sorted in non-decreasing order, we can use 0 to find boundaries via binary search:
- `lower_bound(nums.begin(), nums.end(), 0)` finds the first element >= 0. The index `left` is the count of negative numbers.
- `upper_bound(nums.begin(), nums.end(), 0)` finds the first element > 0. The count of positive numbers is `n - right`.
Return `max(left, n - right)`.
T.C: O(log N)
S.C: O(1)
*/

// Approach 1: Linear Scan O(N)
class SolutionLinear {
public:
    int maximumCount(vector<int>& nums) {
        int pc = 0, nc = 0;
        for (auto n : nums) {
            if (n > 0) {
                pc++;
            } else if (n < 0) {
                nc++;
            }
        }
        return max(pc, nc);
    }
};

// Approach 2: Optimal Binary Search O(log N)
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int left = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int right = upper_bound(nums.begin(), nums.end(), 0) - nums.begin();

        return max(n - right, left);
    }
};
