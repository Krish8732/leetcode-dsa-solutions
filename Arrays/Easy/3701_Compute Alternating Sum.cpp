// LeetCode: https://leetcode.com/problems/compute-alternating-sum/
// Concepts: Array, Simulation

/*
Intuition:
The alternating sum of an array is defined as `nums[0] - nums[1] + nums[2] - nums[3] + ...`

Iterate through the array jumping 2 indices at a time.
Subtract `nums[i+1]` from `nums[i]`. If `i` is the last element (odd array length), add `nums[i]`.

T.C: O(n)
S.C: O(1)
*/

class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i += 2) {
            if (i == n - 1 && n % 2 == 1) {
                sum += nums[i];
            } else {
                sum += (nums[i] - nums[i + 1]);
            }
        }
        return sum;
    }
};
