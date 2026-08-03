// LeetCode: https://leetcode.com/problems/defanging-an-ip-address/
// Concepts: String, Simulation

/*
Approach:
Iterate through each character of the string `address`. If the character is a period '.', append "[.]" to the result string; otherwise, append the character as is.

Time Complexity: O(N) where N is the length of the address string.
Space Complexity: O(N) for storing the result string.
*/

class Solution {
public:
    string defangIPaddr(string address) {
        string res = "";
        for (int i  = 0; i < address.length(); i++) {
            if (address[i] == '.') {
                res += "[.]";
            } else {
                res += address[i];
            }
        }
            return res;
        }
    };
