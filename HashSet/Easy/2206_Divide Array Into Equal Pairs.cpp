// LeetCode: https://leetcode.com/problems/divide-array-into-equal-pairs/
// Concepts: Array, Hash Table, Counting

/*
Intuition:
We are given an integer array `nums` consisting of `2 * n` integers.
We need to divide `nums` into `n` pairs such that each element belongs to exactly one pair and both elements in a pair are equal.
This is possible if and only if every distinct number in `nums` appears an EVEN number of times.

Using `unordered_set`:
- Iterate through each number `i` in `nums`.
- If `i` is already in `remaining` set, erase `i` (pairing it up).
- Otherwise, insert `i` into `remaining`.
- Return `remaining.empty()`.

T.C: O(N) where N is length of nums.
S.C: O(N) space for the set.
*/

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_set<int> remaining;
        for (int i : nums) {
            if (remaining.count(i))
                remaining.erase(i);
            else
                remaining.insert(i);
        }
        return remaining.empty();
    }
};
