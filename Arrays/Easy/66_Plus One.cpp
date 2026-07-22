// Leetcode: https://leetcode.com/problems/plus-one/
// Concepts: Array, Math

// Approach: Traverse from right to left. If sum of digit and 1 is less than 10, update the digit and stop. If it is 10, set to 0 and continue. If the loop completes and carry remains, set the first element to 1 and push_back 0.

// T.C: O(n)
// S.C: O(1)

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int i;
        for (i = n-1; i >= 0; i--){
            int sum = digits[i] + 1;
            if (sum < 10){
                digits[i] = digits[i] + 1;
                break;
            }
            if (sum == 10) digits[i] = 0;  
        }
        if (i == -1){
            digits[0] = 1;
            digits.push_back(0);
        }

        return digits;
    }
};
