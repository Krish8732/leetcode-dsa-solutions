// LeetCode: https://leetcode.com/problems/check-if-array-is-good/
// Concepts: Array, Hash Table, Counting

/*
Intuition:
An array is "good" if it is a permutation of `base[n]` where `base[n] = [1, 2, ..., n - 1, n, n]`.
This means:
1. The size of the array must be `maxEl + 1` where `maxEl` is the maximum element in `nums`.
2. Every number from `1` to `maxEl - 1` must appear **exactly once**.
3. The maximum number `maxEl` must appear **exactly twice**.

We check these conditions using a frequency array while iterating through `nums`.

T.C: O(N) where N is the size of `nums`.
S.C: O(N) auxiliary space for the count array.
*/

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int maxEl = *max_element(begin(nums), end(nums));

        if (nums.size() != maxEl + 1)
            return false;

        vector<int> count(maxEl + 1, 0);

        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;

            if (nums[i] != maxEl && count[nums[i]] > 1)
                return false;
            else if (nums[i] == maxEl && count[nums[i]] > 2)
                return false;
        }

        return true;
    }
};
