// Leetcode: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
// Concepts: Array, Hash Table

/*
Approach 1: Hash Map / Frequency Count
Intuition:
Store the presence of each element in an unordered_map (or hash set).
Iterate through 1 to n; any number not present in the map is added to the result.

T.C: O(n)
S.C: O(n)
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> res;

        for (int x : nums) {
            if (mp[x] != 1)
                mp[x] = 1;
        }

        for (int i = 1; i <= nums.size(); i++) {
            if (mp[i] != 1)
                res.push_back(i);
        }
        return res;
    }
};

/*
Approach 2: In-place Negation (Optimal)
Intuition:
Since the array elements are in the range [1, n], we can use the array indices (0 to n - 1) 
as a hash map.

1. Pass 1: For each element nums[i], mark its corresponding index (abs(nums[i]) - 1) as visited 
   by making the value at that index negative: nums[idx] = -abs(nums[idx]).
2. Pass 2: Iterate through the array. Any positive value at index i means the number (i + 1) 
   was never visited/present in the array. Add (i + 1) to the result.

T.C: O(n)
S.C: O(1) in-place auxiliary space
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;

        for (int i = 0; i < n; i++){
            int idx = abs(nums[i]) - 1;
            nums[idx] = -abs(nums[idx]);
        }

        for (int i = 0; i < n; i++){
            if (nums[i] > 0) result.push_back(i+1);
        }

        return result;
    }
};
