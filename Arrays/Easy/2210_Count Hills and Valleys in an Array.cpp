// LeetCode: https://leetcode.com/problems/count-hills-and-valleys-in-an-array/
// Concepts: Array, Two Pointers

// Approach 1: Removing Adjacent Duplicates using std::unique
/*
Intuition & Explanation:
- Consecutive equal elements belong to the same plateau/hill/valley.
- We first eliminate consecutive duplicates using `std::unique` and `erase`.
- Then, we iterate through the deduplicated array from index `1` to `n-2` and check if `nums[i]` forms a hill (`nums[i-1] < nums[i] > nums[i+1]`) or a valley (`nums[i-1] > nums[i] < nums[i+1]`).

Time Complexity: O(n)
Space Complexity: O(1) auxiliary (in-place modification of vector)
*/

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int hill = 0;
        int valley = 0;
       nums.erase(unique(nums.begin(), nums.end()),nums.end());

       for(int i = 1; i<nums.size()-1; i++){
        if (nums[i-1] > nums[i] && nums[i+1] > nums[i]){
           valley++;
        }
        if (nums[i-1] < nums[i] && nums[i+1] < nums[i]){
            hill++;
        }
       }
       return hill + valley;
    }
};

// Approach 2: One-Pass Two Pointers (Skipping Duplicates In-Place)
/*
Intuition & Explanation:
- To skip duplicate plateaus without modifying the input array, we maintain two pointers:
  - Pointer `i` points to the last non-duplicate left neighbor.
  - Pointer `j` iterates as the current element, comparing with `left = nums[i]` and `right = nums[j+1]`.
- Whenever a valid hill or valley is found between `left`, `curr`, and `right`, increment `result` and update `i = j` (so `curr` becomes the new left neighbor for future elements).
- If `curr == right` (duplicate plateau continuous sequence), pointer `i` stays fixed at the start of the plateau while `j` advances, avoiding duplicate hill/valley counts.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        int i = 0;
        for (int j = 1; j < n - 1; j++) {
            int left = nums[i];
            int right = nums[j + 1];
            int curr = nums[j];

            if (left < curr && curr > right)
                result++, i = j;
            else if (left > curr && curr < right)
                result++, i = j;
        }

        return result;
    }
};
