// LeetCode: https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/
// Concepts: String, Hash Table, Counting

/*
Intuition:
We are given two strings `s1` and `s2` of length `n`.
We can swap characters at indices `i` and `j` if `(j - i)` is even.
Since `j - i` is even, parity `i % 2 == j % 2` is preserved.
This means:
- Any character at an even index can be moved to any other even index.
- Any character at an odd index can be moved to any other odd index.
- Characters can NEVER move between even and odd indices.

1. Maintain two frequency arrays for even and odd indices.
2. Increment counts for `s1` and decrement counts for `s2`.
3. If all frequencies are 0, return `true`, else `false`.

T.C: O(N) where N is length of string.
S.C: O(1) auxiliary space (fixed size 26 array).
*/

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        vector<int> oddIdx (26, 0);
        vector<int> evenIdx (26, 0);

        for (int i = 0; i < n; i++){
            if (i % 2 == 0){
                evenIdx[s1[i] - 'a']++;
                evenIdx[s2[i] - 'a']--;
            }
            else {
                oddIdx[s1[i] - 'a']++;
                oddIdx[s2[i] - 'a']--;
            }
        }

        for(int &x : oddIdx){
            if (x != 0) return false;
        }
        for (int &x : evenIdx){
            if (x != 0) return false;
        }

        return true;
    }
};
