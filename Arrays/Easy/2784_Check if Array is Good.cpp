// LeetCode: https://leetcode.com/problems/check-if-array-is-good/
// Concepts: Array, Hash Table, Counting, In-Place Marking

/*
Intuition:
An array is "good" if it is a permutation of `base[n]` where `base[n] = [1, 2, ..., n - 1, n, n]`.
This means:
1. The size of the array must be `maxElem + 1` where `maxElem` is the maximum element in `nums`.
2. Every number from `1` to `maxElem - 1` must appear **exactly once**.
3. The maximum number `maxElem` must appear **exactly twice**.

Approach 1: Frequency Array / Hash Table
Use an extra frequency array of size `maxElem + 1` to count occurrences.
T.C: O(N) where N is the size of `nums`.
S.C: O(N) auxiliary space for the count array.

Approach 2: Optimal In-Place Bookkeeping (O(1) Auxiliary Space)
Since elements are in range [1, maxElem] and array length is `maxElem + 1`, we use the array itself as a bookkeeping array by negating values at index `val - 1`:
- For `val < maxElem`: mark `nums[val - 1]` as negative. If it is already negative, a duplicate element `< maxElem` exists, so return `false`.
- For `val == maxElem`: count occurrences (`maxCnt++`). If `maxCnt > 2`, return `false`.
T.C: O(N)
S.C: O(1) auxiliary space.
*/

// Approach 1: Frequency Array O(N) Space
class SolutionFrequencyArray {
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

// Approach 2: Optimal In-Place Bookkeeping O(1) Space
class Solution {
public:
    bool isGood(vector<int>& nums) {
        int maxElem = *max_element(nums.begin(), nums.end());

        if (nums.size() != maxElem + 1)
            return false;

        int maxCnt = 0;

        for (int& x : nums) {
            int val = abs(x);

            if (val == maxElem) {
                maxCnt++;
                if (maxCnt > 2)
                    return false;
                continue;
            }

            if (nums[val - 1] < 0)
                return false;

            nums[val - 1] *= -1;
        }

        return true;
    }
};
