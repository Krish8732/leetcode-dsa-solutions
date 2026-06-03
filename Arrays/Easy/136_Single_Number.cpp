// Leetcode: https://leetcode.com/problems/single-number/
// Concepts: Array, HashMap, Bit Manipulation

// Brute Force: check each number against the whole array and return the one with count 1.
// T.C: O(n^2)
// S.C: O(1)

/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] == nums[i]) {
                    cnt++;
                }
            }
            if (cnt == 1) return nums[i];
        }
        return 0;
    }
};
*/

// Better: count frequency with a hash map and return the key with frequency 1.
// T.C: O(n)
// S.C: O(n)

/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int x : nums) mp[x]++;
        for (auto it : mp) {
            if (it.second == 1) return it.first;
        }
        return 0;
    }
};
*/

// Optimal: XOR all numbers; duplicate values cancel out and only the unique value remains.
// T.C: O(n)
// S.C: O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int num : nums) {
            ans ^= num;
        }
        return ans;
    }
};