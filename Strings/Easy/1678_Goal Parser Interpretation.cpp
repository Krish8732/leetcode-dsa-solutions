// LeetCode: https://leetcode.com/problems/goal-parser-interpretation/
// Concepts: String

/*
Intuition:
Iterate through the string `command`: if character is 'G', append 'G'; if it starts "()", append 'o' and advance index by 1; if it starts "(al)", append "al" and advance index by 3.

T.C: O(N) where N is the length of `command`.
S.C: O(N) for storing the result string.
*/

class Solution {
public:
    string interpret(string command) {
        string res;
        for (int i = 0; i < command.length(); i++) {
            if (command[i] == 'G')
                res.push_back('G');
            else if (command[i] == '(' && command[i + 1] == ')') {
                res.push_back('o');
                i += 1;
            } else if (command[i] == '(' && command[i + 1] == 'a' &&
                       command[i + 2] == 'l' && command[i + 3] == ')') {
                res += "al";
                i += 3;
            }
        }
        return res;
    }
};
