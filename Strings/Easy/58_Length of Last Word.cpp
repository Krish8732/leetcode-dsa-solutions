// LeetCode: https://leetcode.com/problems/length-of-last-word/
// Concepts: String

// Approach: Iterate from the end of the string. First skip any trailing spaces, then count characters until the next space is encountered or the beginning of the string is reached.
// TC: O(n) | SC: O(1)

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = 0;
        int totalChar = 0;
        for ( i = s.size() - 1; i>=0; i--){ 
            if(s[i] != ' ') break;
        }
        for (i; i>=0; i--){
            if (s[i] != ' '){
                totalChar ++;
            }
            else break;
        }
        return totalChar;
    }
};
