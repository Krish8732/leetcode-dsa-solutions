// LeetCode: https://leetcode.com/problems/three-consecutive-odds/
// Concepts: Array

/*
Intuition & Explanation:
- Iterate through the array while keeping track of the count of consecutive odd numbers (`cnt`).
- If `arr[i]` is odd (`arr[i] % 2 != 0`), increment `cnt`. If `cnt` reaches 3, break early.
- If `arr[i]` is even, reset `cnt` to 0.
- Return `true` if `cnt == 3`, otherwise `false`.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt = 0;
        int n = arr.size();
        for ( int i = 0; i<n; i++){
            if (arr[i] % 2 != 0){
                cnt ++;
               if (cnt == 3) break;
            }
            else{
                cnt = 0;
            }
        }
        return ( cnt == 3);
    }
};
