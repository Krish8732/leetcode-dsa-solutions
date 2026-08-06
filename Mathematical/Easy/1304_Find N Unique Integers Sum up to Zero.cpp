// LeetCode: https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
// Concepts: Math, Array

// Approach (Symmetric Placement):
// Intuition:
// We need to construct an array of size n containing unique integers that sum up to 0.
// We can achieve this by adding pairs of numbers with opposite signs (e.g., 1 and -1, 2 and -2, ..., i and -i).
// If n is even, we can construct the entire array using n/2 pairs of such numbers.
// If n is odd, we do the same for n - 1 (which is even) and add 0 to make the total count odd and maintain the sum of 0.
// TC: O(n) | SC: O(1) auxiliary space (excluding returned array)

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        res.reserve(n);
        for (int i = 1; i <= n / 2; i++) {
            res.push_back(i);
            res.push_back(-i);
        }
        if (n % 2 != 0) {
            res.push_back(0);
        }
        return res;
    }
};
