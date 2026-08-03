// LeetCode: https://leetcode.com/problems/coupon-code-validator/
// Concepts: String, Hash Table, Sorting

/*
Intuition:
Filter valid coupons based on three criteria:
1. `isActive[i]` must be true.
2. `businessLine[i]` must be one of the recognized categories ("electronics", "grocery", "pharmacy", "restaurant").
3. `code[i]` must be valid (non-empty, consisting only of alphanumeric characters or underscores '_').

Store valid entries as pairs of `(priority_order, code)` so that sorting automatically groups by business line order and then lexicographically by coupon code.

T.C: O(N log N * M) where N is number of coupons and M is maximum code length.
S.C: O(N * M) for storing valid coupons.
*/

class Solution {
public:
    bool checkValidCode(string& code) {
        if (code.empty())
            return false;

        for (char& ch : code) {
            if (!isalnum(ch) && ch != '_')
                return false;
        }

        return true;
    }

    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        unordered_map<string, int> mp = {{"electronics", 0},
                                         {"grocery", 1},
                                         {"pharmacy", 2},
                                         {"restaurant", 3}};

        vector<pair<int, string>> temp;

        for (int i = 0; i < code.size(); i++) {
            if (isActive[i] && mp.count(businessLine[i]) &&
                checkValidCode(code[i])) {
                temp.push_back({mp[businessLine[i]], code[i]});
            }
        }

        sort(begin(temp), end(temp));

        vector<string> result;

        for (auto& it : temp) {
            result.push_back(it.second);
        }

        return result;
    }
};
