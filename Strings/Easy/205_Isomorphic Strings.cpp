// Leetcode: https://leetcode.com/problems/isomorphic-strings/
// Concepts: Hash Table, String

/*
Intuition:
Two strings s and t are isomorphic if characters in s can be mapped one-to-one (bijection) to characters in t.

- We maintain two direct ASCII maps of size 256: mapS (s to t) and mapT (t to s).
- For each character pair (s[i], t[i]):
  1. If s[i] has no mapping yet, assign mapS[s[i]] = t[i].
  2. If t[i] has no mapping yet, assign mapT[t[i]] = s[i].
  3. If current mappings conflict with s[i] or t[i], return false.
- If all characters match bidirectionally without conflicts, return true.

T.C: O(n)
S.C: O(1) - Fixed size array of 256 ASCII characters
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
      int n = s.size();
      int mapS[256] = {0};
      int mapT[256] = {0};
      for ( int i = 0; i < n; i++ ){
        if ( mapS[s[i]] == 0 ) mapS[s[i]] = t[i];
        if ( mapT[t[i]] == 0 ) mapT[t[i]] = s[i];
        if ( mapS[s[i]] != t[i] ) return false;
        if ( mapT[t[i]] != s[i] ) return false;
      }
      return true;
    }
};
