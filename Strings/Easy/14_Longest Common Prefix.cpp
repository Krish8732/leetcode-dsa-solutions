// LeetCode: https://leetcode.com/problems/longest-common-prefix/
// Concepts: String, Trie

// Approach 1 (Horizontal Scanning): Compare the prefix with each string in the list sequentially. Trim the prefix from the end until it matches the prefix of the current string.
// TC: O(S) where S is the sum of all characters in all strings | SC: O(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string prefix = strs[0];
        for (int i = 1; i<strs.size(); i++){
            while (strs[i].find(prefix) != 0){
                prefix = prefix.substr(0, prefix.size() - 1);
                if(prefix.size() == 0) return "";
            }
        }
        return prefix;
    }
};

// Approach 2 (Sorting): Sort the array of strings lexicographically. The common prefix of the entire array must also be common between the lexicographically first and last strings.
// TC: O(N * L * log N) where N is the number of strings and L is the average string length | SC: O(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        sort(strs.begin(), strs.end());
        int a = strs.size();
        int n = strs[0].size();
        int m = strs[a - 1].size();
        int k = min(n, m);
        for (int i = 0; i < k; i++) {
            if (strs[0][i] != strs[a - 1][i]) {
                if (i == 0)
                    return "";
                return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};
