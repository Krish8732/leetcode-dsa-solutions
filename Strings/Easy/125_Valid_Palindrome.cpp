// LeetCode: https://leetcode.com/problems/valid-palindrome/
// Concepts: Strings, Two Pointers

// Approach 1 (Brute Force): Clean the string by extracting only alphanumeric characters in lowercase, then reverse and compare.
// TC: O(n) | SC: O(n)

class Solution {
public:
    bool isPalindrome(string s) {
        string clean = "";
        for (char c : s) {
            if (isalnum(c)) {
                if (isdigit(c))
                    clean += c;
                else {
                    clean += tolower(c);
                }
            }
        }

        string rev = clean;

        reverse(begin(rev), end(rev));

        return rev == clean;
    }
};

// Approach 2 (Optimal): Use two pointers from both ends, skip non-alphanumeric characters, and compare characters in lowercase.
// TC: O(n) | SC: O(1)

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while (i < j) {
            while (i < n - 1 && !isalnum(s[i])) i++;
            while (j > 0 && !isalnum(s[j]))
                j--;
            if (i >= j) break;
            if (tolower(s[i]) != tolower(s[j]))
                return false;
            i++, j--;
        }

        return true;
    }
};
