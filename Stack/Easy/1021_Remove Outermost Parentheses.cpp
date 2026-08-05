// LeetCode: https://leetcode.com/problems/remove-outermost-parentheses/
// Concepts: String, Stack

/*
Approach:
Intuition:
We can track the balance of the parentheses. When we see a '(' and the balance is already greater than 0, it means it is not an outermost parenthesis, so we append it to our result. We then increment the balance. Similarly, when we see a ')' and decrement the balance, if the balance is still greater than 0, it is not an outermost parenthesis, so we append it to the result.

TC: O(n) - Single pass through the string of size n.
SC: O(1) - Auxiliary space complexity (excluding result string).
*/

class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int balance = 0;
        for ( char c : s ){
            if ( c == '('){
                if ( balance > 0 ) res += '(';
                balance++;
            }
            else{
                balance--;
                if ( balance > 0 ) res += ')';
            }
        }
        return res;
    }
};
