// Leetcode: https://leetcode.com/problems/first-unique-character-in-a-string/
// Concepts: Hash Table, String, Queue

/*
Intuition:
Pass 1: Count frequency of each character in s using a fixed array of size 26.
Pass 2: Iterate through s from left to right. The first character with frequency equal to 1 
is the first unique character. Return its 0-based index. If none is found, return -1.

T.C: O(n)
S.C: O(1) - Fixed array of size 26
*/

class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26] = {0};
        for (char c : s) {
            arr[c - 'a']++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (arr[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};
