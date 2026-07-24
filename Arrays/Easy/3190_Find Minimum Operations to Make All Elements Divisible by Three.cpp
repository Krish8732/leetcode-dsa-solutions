// LeetCode: https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/
// Concepts: Array, Math, STL

/*
Intuition:
For any element `x`:
- If `x % 3 == 0`, it is already divisible by 3 (0 operations needed).
- If `x % 3 == 1`, subtract 1 to make it divisible by 3 (1 operation needed).
- If `x % 3 == 2`, add 1 to make it divisible by 3 (1 operation needed).

Thus, every element not divisible by 3 requires exactly 1 operation. The total operations equal the count of elements where `x % 3 != 0`.

Approach 1 (STL count_if with Lambda):
- Uses `std::count_if` with a lambda predicate `[](int x){ return x % 3 != 0; }`.
T.C: O(N)
S.C: O(1)

Approach 2 (Standard Loop):
- Iterate using a range-based for loop and count elements where `x % 3 != 0`.
T.C: O(N)
S.C: O(1)
*/

// Approach 1: STL count_if with Lambda
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        return count_if(nums.begin(), nums.end(), [](int x) {
            return x % 3 != 0;
        });
    }
};

// Approach 2: Standard Range-Based Loop
class SolutionStandardLoop {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;
        for (int x : nums) {
            if (x % 3 != 0) {
                count++;
            }
        }
        return count;
    }
};
