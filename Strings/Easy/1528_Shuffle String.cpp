// LeetCode: https://leetcode.com/problems/shuffle-string/
// Concepts: String, Array

/*
Approach:
Initialize a result string `ans` of size `n` (pre-allocated with spaces) to allow out-of-order index placement without out-of-bounds access.
Iterate through `s` and place `s[i]` at index `indices[i]` in `ans`.

Time Complexity: O(N) where N is the length of string s.
Space Complexity: O(N) for storing the result string.
*/

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = s.size();
        string ans(n, ' ');
        for (int i = 0; i < n; i++) {
            int pos = indices[i];
            ans[pos] = s[i];
        }
        return ans;
    }
};
