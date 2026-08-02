// LeetCode: https://leetcode.com/problems/transformed-array/
// Concepts: Array, Simulation

/*
Intuition & Explanation:
- For each index `i`, we determine the target index `dest` based on `nums[i]`:
  - If `num == 0`: `result[i] = 0` (or `nums[i]`).
  - First, we take `dest0 = abs(num) % n` to find the minimal effective movements within array boundaries.
  - For positive `num`: Move right by `dest0`. If `i + dest0` goes past the last index (`>= n`), we wrap around by subtracting `n`: `i + dest0 - n`.
  - For negative `num`: Move left by `dest0`. If `i - dest0` goes below the first index (`< 0`), we wrap around by adding `n`: `n + i - dest0`.
- Finally, set `result[i] = nums[dest]`.

Time Complexity: O(n)
Space Complexity: O(n) for the result array
*/

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (num == 0) {
                result[i] = 0;
            } else if (num < 0) {
                int dest0 = abs(num) % n;
                int dest = (i - dest0 >= 0) ? i - dest0 : n + i - dest0;
                result[i] = nums[dest];
            } else if (num > 0) {
                int dest0 = num % n;
                int dest = (i + dest0 < n) ? i + dest0 : i + dest0 - n;
                result[i] = nums[dest];
            }
        }

        return result;
    }
};
