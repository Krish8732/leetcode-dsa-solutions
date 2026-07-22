// Leetcode: https://leetcode.com/problems/two-sum/
// Concepts: Array, Hash Map

// Approach: Use a single-pass hash map to store elements and check if the complement (target - nums[i]) already exists.

// T.C: O(n)
// S.C: O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> complementMap;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (complementMap.find(complement) != complementMap.end()) {
                return {complementMap[complement], i};
            }
            complementMap[nums[i]] = i;
        }
        return {};
    }
};
