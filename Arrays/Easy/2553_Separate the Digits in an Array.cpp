// LeetCode: https://leetcode.com/problems/separate-the-digits-in-an-array/
// Concepts: Array, Math, Simulation

/*
Intuition:
Given an array of positive integers `nums`, return an array `result` that contains the digits of each integer in `nums` in the same order.

Approach 1: Per-Element Digit Extraction & Reverse
For each number `num` in `nums`, extract its digits into a temporary array `arr`, reverse `arr`, and append to `result`.
T.C: O(N * log10(M)) where N is size of nums and M is max element value.
S.C: O(log10(M)) auxiliary space per number.

Approach 2: Single Reverse via Backwards Traversal
Iterate `nums` backwards from `n-1` down to 0. Extract digits of each number using `% 10` and `/ 10` directly into `result`.
After processing all numbers, reverse `result` once.
T.C: O(N * log10(M))
S.C: O(1) auxiliary space (excluding output vector).
*/

// Approach 1: Per-Element Digit Extraction & Reverse
class SolutionPerElement {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;
        for (int& num : nums) {
            vector<int> arr;
            while (num > 0) {
                int temp = num % 10;
                arr.push_back(temp);
                num /= 10;
            }
            reverse(arr.begin(), arr.end());
            for (int n : arr) {
                result.push_back(n);
            }
        }

        return result;
    }
};

// Approach 2: Single Reverse via Backwards Traversal
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        for (int i = n - 1; i >= 0; i--) {
            int num = nums[i];
            while (num > 0) {
                int temp = num % 10;
                result.push_back(temp);
                num /= 10;
            }
        }
        reverse(result.begin(), result.end());

        return result;
    }
};
