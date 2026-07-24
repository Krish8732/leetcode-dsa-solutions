// LeetCode: https://leetcode.com/problems/trionic-array-i/
// Concepts: Array, Simulation, State Machine

/*
Intuition:
An array `nums` is trionic if it can be partitioned into 3 consecutive non-empty segments:
1. Strictly Increasing (`startInc`)
2. Strictly Decreasing (`middleDec`)
3. Strictly Increasing (`endInc`)

We maintain state counters `startInc`, `middleDec`, and `endInc` to track transitions across the array in a single pass.
- Verify `nums[1] > nums[0]` to initialize `startInc`.
- While traversing `i` from 2 to `n-1`:
  - Increment `startInc` if `nums[i] > nums[i-1]` and decreasing/ending phases haven't started.
  - Increment `middleDec` if `nums[i] < nums[i-1]` and ending phase hasn't started.
  - Increment `endInc` if `nums[i] > nums[i-1]` after starting both `startInc` and `middleDec`.
  - Return `false` if `nums[i] == nums[i-1]` or invalid state transitions occur.
- Return `true` if all 3 phase counts `startInc > 0 && middleDec > 0 && endInc > 0`.

T.C: O(n)
S.C: O(1)
*/

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int startInc = 0;
        int middleDec = 0;
        int endInc = 0;

        if (nums[1] <= nums[0]) return false;

        startInc++;

        for (int i = 2; i < n; i++){
            if (nums[i] > nums[i-1] && middleDec == 0 && endInc == 0){
                startInc++;
            }

            else if (nums[i] < nums[i-1]){
                if (startInc > 0 && endInc == 0){
                    middleDec++;
                } else return false;
            }

            else if (nums[i] > nums[i-1] && startInc > 0 && middleDec > 0){
                endInc++;
            }

            else if (nums[i] == nums[i-1]) return false;
        }

        return (startInc > 0 && middleDec > 0 && endInc > 0) ? true : false;
    }
};
