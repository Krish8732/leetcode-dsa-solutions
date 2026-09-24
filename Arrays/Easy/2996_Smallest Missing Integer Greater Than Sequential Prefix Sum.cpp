// LeetCode: https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/
// Concepts: Array, Hash Table, Counting

/*
Intuition:
First, find the sum of the longest sequential prefix of `nums` (starts at index 0 and increases by 1 for each element).
Then find the smallest integer `x >= sum` that does not exist in `nums`.

Approach:
1. Iterate through `nums` starting at index 1 to calculate the sequential prefix sum. Stop as soon as `nums[i] != nums[i - 1] + 1`.
2. Record presence of elements in `nums` using a frequency array.
3. Starting from `sum`, check if the number exists in the array; return the first number >= `sum` that is missing.

T.C: O(N) where N is the length of `nums`.
S.C: O(1) auxiliary space (array of fixed size 51).
*/

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        int arr[51] = {0};

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1)
                sum += nums[i];
            else
                break;
        }

        if (sum > 50)
            return sum;

        for (int i = 0; i < n; i++) {
            arr[nums[i]] = 1;
        }

        int i;

        for (i = sum; i <= 50; i++) {
            if (arr[i] == 0) {
                break;
            }
        }

        return i;
    }
};
