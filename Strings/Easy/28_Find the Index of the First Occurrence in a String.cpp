// LeetCode: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
// Concepts: String, Two Pointers, String Matching

// Approach 1 (Brute Force / Two Pointers): Iterate through the haystack with index `i` up to `m - n`. For each `i`, check if the substring starting at `i` matches `needle` character by character.
// TC: O((m - n) * n) where m is haystack length and n is needle length | SC: O(1)

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n= needle.size();

        if (m == 0) return -1;

        for(int i = 0; i<=m-n; i++ ){
            int j;
            for( j = 0; j<n; j++){
                if (haystack[i+j] != needle[j]) break;
                if (haystack[i+j] == needle[j]) continue;
            }
            if (j == n) return i;
        }
        return -1;
    }
};

// Approach 2 (Built-in Find): Use C++ standard library string find method.
// TC: O(m * n) worst case (implementation dependent) | SC: O(1)

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size())
            return -1;

        auto firstOcc = haystack.find(needle);

        return (firstOcc != string::npos) ? firstOcc : -1;
    }
};
