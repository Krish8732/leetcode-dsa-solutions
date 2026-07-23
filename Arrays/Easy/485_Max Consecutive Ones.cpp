// Leetcode: https://leetcode.com/problems/max-consecutive-ones/
// Concepts: Array

/*
Intuition:
Iterate through the array while maintaining a running count of consecutive 1s (cnt).
- If nums[i] == 1, increment cnt and update maximum (maxn = max(maxn, cnt)).
- If nums[i] == 0, reset cnt to 0.

T.C: O(n)
S.C: O(1)
*/

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
