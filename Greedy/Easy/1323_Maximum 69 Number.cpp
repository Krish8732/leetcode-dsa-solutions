// LeetCode: https://leetcode.com/problems/maximum-69-number/
// Concepts: Greedy, Strings

// Approach: Convert number to string, find the first '6' from the left and change it to '9' for the maximum possible value.

// TC: O(d) where d = number of digits | SC: O(d)

class Solution {
public:
    int maximum69Number (int num) {
  string str = to_string(num);
  for ( int i = 0; i < str.length(); i++){
     if (str[i] == '6'){
        str[i] = '9';
      break;
      };
  }
  num = stoi(str);
  return num;
  }
};
