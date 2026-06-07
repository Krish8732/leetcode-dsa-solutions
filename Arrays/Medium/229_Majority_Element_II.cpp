// LeetCode: https://leetcode.com/problems/majority-element-ii/
// Concepts: Array, Boyer-Moore Voting Algorithm

// Approach: Extended Boyer-Moore Voting Algorithm - track two candidates and their counts. At most 2 elements can appear more than n/3 times. Cancel out different elements, then verify frequencies to ensure they exceed n/3.

// TC: O(n) | SC: O(1)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candid1 = 0;
        int candid2 = 0;
        int n = nums.size();
        int cnt1 = 0;
        int cnt2 = 0;

        for (int i = 0; i < n; i++) {
            int curr = nums[i];

            if (curr == candid1)
                cnt1++;
            else if (curr == candid2)
                cnt2++;
            else if (cnt1 == 0) {
                candid1 = curr;
                cnt1 = 1;
            } else if (cnt2 == 0) {
                candid2 = curr;
                cnt2 = 1;
            } else {
                cnt1--, cnt2--;
            }
        }

        vector<int> res;
        int freq1 = 0, freq2 = 0;

        for (int x : nums) {
            if (x == candid1)
                freq1++;
            else if (x == candid2)
                freq2++;
        }

        if (freq1 > n / 3)
            res.push_back(candid1);
        if (freq2 > n / 3)
            res.push_back(candid2);

        return res;
    }
};
