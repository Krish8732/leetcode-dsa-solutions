// LeetCode: https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/
// Concepts: Array, Hash Table, HashSet

/*
Intuition:
In an array `nums` of size `n + 2`, numbers `0` through `n - 1` are present, but exactly two numbers appear twice. We need to find and return those two sneaky numbers.

1. Maintain an `unordered_set<int> dville` to keep track of visited numbers.
2. Iterate through `nums`. If `x` is already in `dville`, append `x` to `res`. Otherwise, insert `x` into `dville`.
3. Return `res` containing the two sneaky numbers.

T.C: O(N)
S.C: O(N)
*/

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_set<int> dville;
        vector<int> res;
        for (int x : nums) {
            if (dville.count(x)) res.push_back(x);
            else {
                dville.insert(x);
            }
        }
        return res;
    }
};
