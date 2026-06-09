// LeetCode: https://leetcode.com/problems/max-consecutive-ones/
// Concepts: Arrays, Single Pass

// Approach: Iterate through the array, counting consecutive 1s. Reset counter on 0, track the maximum count seen.

// TC: O(n) | SC: O(1)

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxn = 0, cnt = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if (nums[i] == 1){
                cnt ++;
                maxn = max(cnt, maxn);
            }
            else {
                cnt = 0;
            }
        }
        return maxn;
    }
};

