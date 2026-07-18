// LeetCode: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Concepts: Array, Two Pointers

// Approach: Use two pointers. `j` tracks the position of the last unique element found. Iterate with `i` and whenever a new element is found (different from nums[j]), increment `j` and copy the element to nums[j].
// TC: O(n) | SC: O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int j = 0;
        for(int i = 1; i<nums.size(); i++){
            if (nums[i] != nums[j]){
                j++;
                nums[j] = nums[i];
            }
        }
        return j+1;
    }
};
