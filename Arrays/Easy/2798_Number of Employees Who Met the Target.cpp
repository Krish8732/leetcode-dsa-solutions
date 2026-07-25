// LeetCode: https://leetcode.com/problems/number-of-employees-who-met-the-target/
// Concepts: Array, Counting

/*
Intuition:
We are given an integer array `hours` where `hours[i]` represents the number of hours the i-th employee worked, and a non-negative integer `target`.
We need to count and return the number of employees who worked at least `target` hours.

Iterate through `hours` and increment `cnt` for every element `x >= target`.

T.C: O(N) where N is the length of `hours`.
S.C: O(1) auxiliary space.
*/

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int cnt = 0;
        for (int x : hours) {
            if (x >= target) cnt++;
        }
        return cnt;
    }
};
