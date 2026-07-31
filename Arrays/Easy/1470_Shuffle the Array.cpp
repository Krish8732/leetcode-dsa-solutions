// LeetCode: https://leetcode.com/problems/shuffle-the-array/
// Concepts: Array, Two Pointers, Math Encoding

/*
Intuition & Approaches:

1. Basic Approach (Extra Space - O(N)):
   Create a new result vector of size 2*n. Loop `i` from 0 to n-1 and push `nums[i]` followed by `nums[i+n]`.
   - T.C: O(N)
   - S.C: O(N) extra space.

2. In-Place Approach (O(1) Auxiliary Space using Number Encoding):
   We can encode two numbers into a single integer position using modulo arithmetic: `encoded = num1 + (num2 * M)` where `M > max(nums)`.
   
   - Step 1: Store pairs in the second half of the array `nums[n...2n-1]`.
     For `i` from `n` to `2n-1`: `nums[i] = nums[i-n] + (nums[i] * M)`.
     Here, `nums[i-n]` is the original first half element (`x_i`), and `nums[i]` is the second half element (`y_i`).
   - Step 2: Extract both stored values and place them into their target positions starting from index 0.
     For `i` from `n` to `2n-1` with target pointer `j` starting at 0:
     `nums[j]   = nums[i] % M` (retrieves x_i)
     `nums[j+1] = nums[i] / M` (retrieves y_i)
     Then increment `j` by 2.



T.C: O(N)
S.C: O(1) auxiliary space (in-place modification).
*/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int m = *max_element(nums.begin(), nums.end()) + 1;
        for (int i = n; i < 2 * n; i++) {
            nums[i] = nums[i - n] + (nums[i] * m);
        }

        int j = 0;

        for (int i = n; i < 2 * n; i++, j += 2) {
            nums[j] = nums[i] % m;
            nums[j + 1] = nums[i] / m;
        }

        return nums;
    }
};
