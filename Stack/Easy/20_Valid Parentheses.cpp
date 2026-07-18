// LeetCode: https://leetcode.com/problems/valid-parentheses/
// Concepts: String, Stack

// Approach: Use a stack to track opening brackets. When a closing bracket is encountered, verify if it matches the top of the stack. If it does, pop it; otherwise, the string is invalid.
// TC: O(n) | SC: O(n)

class Solution {
public:
    bool isValid(string s) {    
        stack<char> st;
        for (int i = 0; i<s.size(); i++){
            if (s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else if (s[i] == ')' || s[i] == '}' || s[i] == ']'){
                if (st.empty()) return false;
                char topChar = st.top();
                st.pop();
                if ((topChar == '(' && s[i] != ')') ||
                    (topChar == '{' && s[i] != '}') ||
                    (topChar == '[' && s[i] != ']'))
                    return false;
                }
            }
        return st.empty();
    }
};
