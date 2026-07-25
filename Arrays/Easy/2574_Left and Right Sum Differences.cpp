// LeetCode: https://leetcode.com/problems/left-and-right-sum-differences/
// Concepts: Array, Prefix Sum

/*
Intuition:
Given a 0-indexed integer array `nums`, find an answer array `answer` where `answer[i] = |leftSum[i] - rightSum[i]|`.
- `leftSum[i]` is the sum of elements to the left of index `i`.
- `rightSum[i]` is the sum of elements to the right of index `i`.

Approach 1: Prefix / Suffix Sum using Extra Answer Vector
1. Compute total `sum` of all elements.
2. Iterate `i` from 0 to n-1:
   - `leftSum += (i > 0) ? nums[i - 1] : 0`
   - `rightSum = sum - leftSum - nums[i]`
   - `answer[i] = abs(leftSum - rightSum)`
T.C: O(N)
S.C: O(N) for output vector.

Approach 2: Optimal In-Place Modification (O(1) Auxiliary Space)
If modifying input in-place is permitted, we can capture original `val = nums[i]`, compute `rightSum = sum - leftSum - val`, set `nums[i] = abs(leftSum - rightSum)`, and update `leftSum += val`.
T.C: O(N)
S.C: O(1) auxiliary space.
*/

// Approach 1: Separate Answer Array
class SolutionSeparateArray {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int x : nums) {
            sum += x;
        }

        int leftSum = 0;
        int rightSum = 0;
        vector<int> answer(n);

        for (int i = 0; i < n; i++) {
            leftSum += (i > 0) ? nums[i - 1] : 0;
            rightSum = sum - leftSum - nums[i];
            answer[i] = abs(leftSum - rightSum);
        }

        return answer;
    }
};

// Approach 2: Optimal In-Place Modification (O(1) Auxiliary Space)
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int x : nums) sum += x;

        int leftSum = 0;
        for (int i = 0; i < n; i++) {
            int val = nums[i];
            int rightSum = sum - leftSum - val;
            nums[i] = abs(leftSum - rightSum);
            leftSum += val;
        }

        return nums;
    }
};
