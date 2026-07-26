// LeetCode: https://leetcode.com/problems/final-value-of-variable-after-performing-operations/
// Concepts: Array, String, Simulation

/*
Intuition:
Each operation either increases or decreases the value of X by 1.
Notice that in all four operation strings ("++X", "X++", "--X", "X--"), the middle character (index 1) is always '+' for increments and '-' for decrements.
Count the number of increment operations. The final value can be calculated as `2 * increment - total_operations` (starting from 0).

T.C: O(N) where N is the number of operations.
S.C: O(1) auxiliary space.
*/

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int increment = 0;
        for  (const string &s : operations){
            if ( s[1] == '+' ) increment++;
        }
        return 2*(increment) - operations.size();
    }
};
