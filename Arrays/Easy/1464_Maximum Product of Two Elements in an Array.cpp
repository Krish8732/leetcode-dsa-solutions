// LeetCode: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
// Concepts: Array, Sorting, Heap (Priority Queue)

/*
Intuition:
To maximize (nums[i] - 1) * (nums[j] - 1), we need to find the two largest elements in the array `max1` and `max2`.
We iterate through `nums` in a single pass to track the largest and second largest elements.
Finally, we return (max1 - 1) * (max2 - 1).

T.C: O(N)
S.C: O(1)
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 1, max2 = 1;

        for (int x : nums) {
            if (x >= max1) {
                max2 = max1;
                max1 = x;
            } else if (x >= max2) {
                max2 = x;
            }
        }

        return (max1 - 1) * (max2 - 1);
    }
};
