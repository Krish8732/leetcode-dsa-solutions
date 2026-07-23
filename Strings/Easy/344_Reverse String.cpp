// Leetcode: https://leetcode.com/problems/reverse-string/
// Concepts: Two Pointers, String

/*
Intuition:
Use a two-pointer approach starting at opposite ends of the vector (i = 0, j = size - 1).
Swap the characters at i and j, then move pointers towards each other (i++, j--) until they meet.

T.C: O(n)
S.C: O(1) in-place
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0;
        int j = s.size() - 1;
        while (i<j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};
