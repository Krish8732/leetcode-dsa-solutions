// LeetCode: https://leetcode.com/problems/unique-middle-element/
// Concepts: Array

/*
Approach: Find the middle element at index n/2. Count the occurrences of this element in the array.
Return true if the count is exactly 1, otherwise false.
TC: O(n) - Single pass traversal to count occurrences of the middle element.
SC: O(1) - Constant auxiliary space.
*/

class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int num = nums[n/2];
        int cnt = 0;
        for (int x: nums){
            if (x == num) cnt++;
        }

        return cnt == 1;
    }
};
