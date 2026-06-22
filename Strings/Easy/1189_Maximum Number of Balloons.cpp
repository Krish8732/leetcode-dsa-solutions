// LeetCode: https://leetcode.com/problems/maximum-number-of-balloons/
// Concepts: Strings, Hash Table, Counting

// Approach: Count the occurrences of characters 'b', 'a', 'l', 'o', 'n' in the text, and then find how many "balloon" words we can form. Since 'l' and 'o' appear twice in "balloon", we decrement them by 2 for each word.
// TC: O(n) | SC: O(1)

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int a = 0, b = 0, l = 0, o = 0, n = 0;
        for (char c : text) {
            if (c == 'a')
                a++;
            if (c == 'b')
                b++;
            if (c == 'l')
                l++;
            if (c == 'o')
                o++;
            if (c == 'n')
                n++;
        }

        int cnt = 0;
        while (a > 0 && b > 0 && n > 0 && l > 1 && o > 1) {
            a--, b--, n--;
            l -= 2, o -= 2;
            cnt++;
        }

        return cnt;
    }
};
