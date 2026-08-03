// LeetCode: https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/
// Concepts: Array, String, Hash Table, Counting

/*
Intuition:
Iterate through the array of words while maintaining a result list.
For each word, compare it with the last added word in `result` using a helper function `checkAnagram`.
`checkAnagram` uses a frequency count array of size 26 to verify if two strings are anagrams.
If the current word is NOT an anagram of `result.back()`, append it to `result`.

T.C: O(N * M) where N is the number of words and M is the maximum length of a word.
S.C: O(1) auxiliary space (excluding the output result array).
*/

class Solution {
public:

    bool checkAnagram(string& s1, string& s2){
        int arr[26] = {0};

        if ( s1.size() != s2.size() ) return false;

        for ( int i = 0; i < s1.size(); i++ ){
            arr[s1[i] - 'a']++;
            arr[s2[i] - 'a']--;
        }

        for ( int x : arr ){
            if ( x != 0 ) return false;
        }

        return true;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();

        vector<string> result;

        result.push_back(words[0]);

        for ( int i = 1; i < n; i++ ){
            if ( !checkAnagram(words[i], result.back()) ){
                result.push_back(words[i]);
            }
        }

        return result;
    }
};
