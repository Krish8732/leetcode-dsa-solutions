// LeetCode: https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/
// Concepts: Math, Prefix GCD, Sorting, Two Pointers

/*
Approach:
just simulate what is asked 

TC: O(n log n + n log M) - where n is the length of nums and M is the maximum element in nums.
SC: O(n) - for storing the prefixGcd array.
*/

class Solution {
public:
    typedef long long ll;
    ll gcdSum(vector<int>& nums) {
        int n = nums.size();
        int maxElem = 1;
        vector<int> prefixGcd(n);

        for (int i = 0; i < n; i++) {
            maxElem = max(maxElem, nums[i]);
            prefixGcd[i] = gcd(nums[i], maxElem);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        ll sum = 0;
        int i = 0, j = n - 1;

        while (i < j) {
            int currGcd = gcd(prefixGcd[i], prefixGcd[j]);
            sum += currGcd;
            i++, j--;
        }

        return sum;
    }
};
