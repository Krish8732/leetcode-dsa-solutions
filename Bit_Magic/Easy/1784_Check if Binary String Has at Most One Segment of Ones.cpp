// LeetCode: https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/
// Concepts: String, Bit Manipulation

// Approach 1 (Iterative State Tracking):
// Intuition:
// Since s starts with '1', we can scan s from left to right. We track if the segment of '1's has been "broken" (transitioned to '0'). If we find another '1' after the segment is broken, it means there are at least two segments of ones, so we return false.
// TC: O(n) | SC: O(1)

class Solution {
public:
    bool checkOnesSegment(string s) {
        bool broken = false;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1])
                continue;
            if (s[i] == '0')
                broken = true;
            if (s[i] == '1' && broken)
                return false;
        }

        return true;
    }
};

// Approach 2 (Substring Search Optimization):
// Intuition:
// Since the string has no leading zeros (it starts with '1'), a string has at most one segment of ones if and only if it does not contain the substring "01". If it does contain "01", that indicates a second segment of ones starting after some zeros.
// TC: O(n) | SC: O(1)

class Solution {
public:
    bool checkOnesSegment(string s) {
        return s.find("01") == string::npos;
    }
};
