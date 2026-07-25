// LeetCode: https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/
// Concepts: String, Two Pointers

/*
Intuition:
Iterate over all index pairs (i, j) with i < j and check if words[i] is both a prefix and a suffix of words[j].

T.C: O(N^2 * L) where N is number of words and L is max word length
S.C: O(1)
*/

class Solution {
public:
    bool isPrefixAndSuffix(string& s1, string& s2) {
        if (s1.size() > s2.size()) return false;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i])
                return false;
            if (s1[i] != s2[s2.size() - s1.size() + i])
                return false;
        }

        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int idxPairs = 0;
        for (int j = n - 1; j > 0; j--) {
            for (int i = 0; i < j; i++) {
                if (isPrefixAndSuffix(words[i], words[j]))
                    idxPairs++;
            }
        }

        return idxPairs;
    }
};
