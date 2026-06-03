// Leetcode: https://leetcode.com/problems/remove-element/
//Concepts: Array, Two pointers

//Approach: start inserting from start whenver found and increment the pointer.

//T.C: O(n)
//S.C: 0

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int k = 0; // Initialize the count of elements not equal to val
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[k++] = nums[i]; // Move non-val elements to the front
            }
        }
        return k; // Return the count of elements not equal to val
    }
};
