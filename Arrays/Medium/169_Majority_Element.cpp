// LeetCode: https://leetcode.com/problems/majority-element/
// Concepts: Array, Boyer-Moore Voting Algorithm

// Approach: Boyer-Moore Voting Algorithm - maintain a candidate and its count. When counts cancel out, update the candidate. The majority element (appearing > n/2 times) will always remain.

// TC: O(n) | SC: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candid = nums[0];
        int cnt = 1;
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            int curr = nums[i];
            if (curr == candid)
                cnt++;
            else {
                if (cnt == 0) {
                    cnt = 1;
                    candid = curr;
                } else
                    cnt--;
            }
        }

        return candid;
    }
};
