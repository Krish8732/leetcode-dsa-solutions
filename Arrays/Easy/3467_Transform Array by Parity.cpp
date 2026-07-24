// LeetCode: https://leetcode.com/problems/transform-array-by-parity/
// Concepts: Array, Sorting, Counting

/*
Intuition:
We are asked to transform an array by replacing even elements with 0 and odd elements with 1, then sorting in non-decreasing order.

Approach 1 (In-place Replacement & Sorting):
- Iterate through `nums`, replace `x` with 0 if even, else 1.
- Sort `nums`.
T.C: O(N log N)
S.C: O(1)

Approach 2 (Counting Parities - Linear Time):
- Count number of even numbers (`evenCnt`) and odd numbers (`oddCnt`).
- Initialize a result array of size `oddCnt + evenCnt` with 0s.
- Fill values from `evenCnt` to end with 1s (naturally sorted non-decreasingly).
T.C: O(N)
S.C: O(N)
*/

// Approach 1: In-place Replacement & Sorting
class SolutionSorting {
public:
    vector<int> transformArray(vector<int>& nums) {
        for (int &x : nums) {
            if (x % 2 == 0) x = 0;
            else x = 1;
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};

// Approach 2: Counting Even/Odd Frequencies (Optimal O(N))
class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int oddCnt = 0, evenCnt = 0;

        for (int &x : nums) {
            if (x % 2 == 0) evenCnt++;
            else oddCnt++;
        }

        vector<int> result(oddCnt + evenCnt, 0);

        for (int i = evenCnt; i < result.size(); i++) {
            result[i] = 1;
        }

        return result;
    }
};
