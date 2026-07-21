// LeetCode: https://leetcode.com/problems/number-of-zero-filled-subarrays/
// Concepts: Array, Math

// Approach 1 (Math / Counting): Count contiguous segments of 0s.
// A segment of length L contains L * (L + 1) / 2 subarrays.
// Sum these up for all segments.
// TC: O(N) | SC: O(1)

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long zarray = 0;
        long long sum = 0;
        long long cnt = 0;
        for (int i = 0; i<n; i++){
            if ( nums[i] == 0 ){
                cnt ++;
            }
            else {
            zarray = (cnt*(cnt+1))/2;
            sum += zarray;
                cnt = 0;
            }
        }
        if (cnt > 0){
            zarray = (cnt*(cnt+1))/2;
            sum += zarray;
        }
        return sum;
    }
};
