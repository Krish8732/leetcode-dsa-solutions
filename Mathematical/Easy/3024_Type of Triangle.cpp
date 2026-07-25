// LeetCode: https://leetcode.com/problems/type-of-triangle/
// Concepts: Array, Math, Geometry

/*
Intuition:
A triangle can be formed by three side lengths if and only if the sum of any two side lengths is strictly greater than the third side length (Triangle Inequality Theorem).

1. Check triangle inequality: if any pair sum <= third side, return "none".
2. If all three sides are equal, return "equilateral".
3. If any two sides are equal, return "isosceles".
4. Otherwise, return "scalene".

T.C: O(1) since array size is fixed at 3.
S.C: O(1) auxiliary space.
*/

class Solution {
public:
    string triangleType(vector<int>& nums) {
       if (nums[0] + nums[1] <= nums[2] || nums[1] + nums[2] <= nums[0] ||
            nums[0] + nums[2] <= nums[1])
            return "none";
        else if (nums[0] == nums[1] && nums[1] == nums[2])
            return "equilateral";
        else if (nums[0] == nums[1] || nums[0] == nums[2] || nums[1] == nums[2])
            return "isosceles";
        else 
            return "scalene";
    }
};
