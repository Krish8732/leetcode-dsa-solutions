// LeetCode: https://leetcode.com/problems/number-of-good-pairs/
// Concepts: Array, Hash Table, Math, Counting

/*
Intuition & Approaches:

1. Brute Force (O(N^2) Time, O(1) Space):
   Use nested loops to check every pair (i, j) with 0 <= i < j < n.
   If nums[i] == nums[j], increment count.

2. Optimized Single-Pass Frequency Array (O(N) Time, O(1) Auxiliary Space):
   Instead of checking past elements repeatedly, keep track of how many times each number has appeared so far using a frequency array.
   When visiting element `x`, it can form a new good pair with every previous occurrence of `x` (which is `freq[x]`).
   So we add `freq[x]` to `pairsCnt` first, and then increment `freq[x]`.

T.C: O(N) where N is the length of `nums`.
S.C: O(1) auxiliary space (fixed-size array of size 101 since 1 <= nums[i] <= 100).
*/

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int arr[101] = {0};
        int pairsCnt = 0;

        for (int x : nums) {
            pairsCnt += arr[x]++;
        }

        return pairsCnt;
    }
};
