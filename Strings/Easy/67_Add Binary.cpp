// Leetcode: https://leetcode.com/problems/add-binary/
// Concepts: String, Math, Two Pointers

// Approach: Use two pointers starting from the end of both strings. Add digits along with carry, append (sum % 2) as a character, and determine carry as (sum > 1). Reverse the final result.

// T.C: O(max(n, m))
// S.C: O(1)

class Solution {
public:
    string addBinary(string a, string b) {

        int carry = 0;
        int sum = 0;
        string result = "";

        int i = a.size() - 1;
        int j = b.size() - 1;

        while (i >= 0 || j >= 0) {

            int val1 = (i >= 0) ? a[i] - '0' : 0;
            int val2 = (j >= 0) ? b[j] - '0' : 0;

            sum = carry + val1 + val2;
            result.push_back((sum % 2) == 0 ? '0' : '1');
            carry = (sum > 1) ? 1 : 0;

            i--, j--;
        }

        if (carry) {
            result.push_back('1');
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
