// LeetCode: https://leetcode.com/problems/maximum-product-of-three-numbers/
// Concepts: Array, Math, Sorting

/* 
Approach 1 (Sorting): Sort the array and return the maximum of the product of the three largest numbers or the product of the two smallest numbers and the largest number.
TC: O(n log n) | SC: O(1) (or O(log n) depending on sort implementation)
*/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return max(nums[0] * nums[1] * nums[n-1], nums[n-1] * nums[n-2] * nums[n-3]);
    }
};

/* 
Approach 2 (Single Pass - Optimal): Find the 3 maximum numbers and 2 minimum numbers in a single iteration without sorting.
TC: O(n) | SC: O(1)
*/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;

        for (int n : nums) {
            if (n >= max1) {
                max3 = max2;
                max2 = max1;
                max1 = n;
            } else if (n >= max2) {
                max3 = max2;
                max2 = n;
            } else if (n >= max3) {
                max3 = n;
            }

            if (n <= min1) {
                min2 = min1;
                min1 = n;
            } else if (n <= min2) {
                min2 = n;
            }
        }

        return max(max1 * max2 * max3, min1 * min2 * max1);
    }
};
