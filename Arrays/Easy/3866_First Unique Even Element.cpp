// Leetcode: https://leetcode.com/problems/first-unique-even-element/
// Concepts: Array, Hash Table

/*
Intuition:
Pass 1: Count frequency of each number using an unordered_map (or frequency array).
Pass 2: Iterate through nums from left to right. The first even number (x % 2 == 0) 
with frequency equal to 1 is returned immediately. If no such number exists, return -1.

T.C: O(n)
S.C: O(n)
*/

class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int x : nums) {
            mp[x]++;
        }
        for (int x : nums) {
            if (x % 2 == 0 && mp[x] == 1) {
                return x;
            }
        }
        return -1;
    }
};
