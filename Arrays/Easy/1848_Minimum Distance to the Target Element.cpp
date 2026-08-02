// LeetCode: https://leetcode.com/problems/minimum-distance-to-the-target-element/
// Concepts: Array

/*
Intuition & Explanation:
- Iterate through the array `nums` to find all indices `i` where `nums[i] == target`.
- For every matching index, calculate the absolute distance from `start`: `abs(i - start)`.
- Track and return the minimum absolute distance found (`minDiff`).

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int minDiff = INT_MAX;
        for (int i = 0; i < n; i++){
            if (nums[i] == target){
                int diff = abs(i - start);
                minDiff = min(minDiff, diff);
            }
        }

        return minDiff;
    }
};
