// LeetCode: https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/
// Concepts: Array, Math, Simulation

/*
Intuition:
We replace each element in `nums` with the sum of its digits, then return the minimum element among all replacements.

1. Initialize `minElem` to a large value (e.g. 1e5 or INT_MAX).
2. For each number `num` in `nums`:
   - Compute its digit sum `val` by repeatedly taking `num % 10` and `num /= 10`.
   - Update `minElem = min(minElem, val)`.
3. Return `minElem`.

T.C: O(N * log10(M)) where N is length of nums and M is maximum element value.
S.C: O(1)
*/

class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();
        int minElem = 1e5;
        for (int& num : nums) {
            int val = 0;
            while (num > 0) {
                val += num % 10;
                num = num / 10;
            }
            minElem = min(minElem, val);
        }

        return minElem;
    }
};
