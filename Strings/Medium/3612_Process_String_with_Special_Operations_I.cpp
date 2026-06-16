// LeetCode: https://leetcode.com/problems/process-string-with-special-operations-i/
// Concepts: Strings, Simulation

// Approach: Use a string to simulate the operations. Traverse through each character:

// TC: O(n * L) where n is length of s and L is the max length of the result | SC: O(1) 
class Solution {
public:
    string processStr(string s) {
        string result = "";

        for (char& c : s) {

            int n = result.size();

            if (c == '*' && n > 0) {
                result.pop_back();
            } else if (c == '#' && n > 0) {
                string temp = result;
                result += temp;
            } else if (c == '%' && n > 0) {
                reverse(result.begin(), result.end());
            } else if (c != '*' && c != '#' && c != '%') {
                result += c;
            }
        }

        return result;
    }
};
