// Leetcode: https://leetcode.com/problems/valid-anagram/
// Concepts: Hash Table, String, Sorting

/*
Approach 1: Sorting
Sort both strings. If they are anagrams, their sorted versions will be identical.

T.C: O(n log n)
S.C: O(1) or O(n) depending on sort implementation
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return (s == t); 
    }
};

/*
Approach 2: Frequency Array (Optimal for lowercase English letters)
Intuition:
Count frequency of each character. Increment count for characters in s and decrement for characters in t.
If all counts return to 0, strings are anagrams.

Note for Unicode / arbitrary characters:
If input contains Unicode characters, replace the fixed array of size 26 with a hash map 
(unordered_map<char, int> or unordered_map<uint32_t, int>).

T.C: O(n)
S.C: O(1) - Fixed array of size 26
*/

class Solution {
public:
    bool isAnagram(string s, string t) {

       if ( s.size() != t.size() ) return false;

       int count[26] = {0};

       for ( int i = 0; i < s.size(); i++ ){
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
       }

       for ( int x : count ){
        if ( x != 0 ) return false;
       }

       return true;
    }
};
