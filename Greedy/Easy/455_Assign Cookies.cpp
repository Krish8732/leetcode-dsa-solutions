// Leetcode: https://leetcode.com/problems/assign-cookies/
// Concepts: Array, Two Pointers, Greedy, Sorting

/*
Intuition (Greedy Approach):
Sort both the greed factors array g and cookie sizes array s in non-decreasing order.

Greedy Strategy:
Try to satisfy the child with the smallest greed factor using the smallest cookie that is 
large enough to satisfy them (s[j] >= g[i]).

- If cookie j can satisfy child i (s[j] >= g[i]), assign it: increment count, move both i and j.
- If cookie j is too small (s[j] < g[i]), move to the next larger cookie (j++) because cookie j 
  cannot satisfy any subsequent child either.

T.C: O(n log n + m log m) where n = children count, m = cookie count
S.C: O(1) auxiliary space
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int children = g.size();
        int cookies = s.size();

        int i = 0;
        int j = 0;

        int count = 0;

        while (i < children && j < cookies){
            if (s[j] >= g[i]){
                count++;
                i++, j++;
            }
            else if (s[j] < g[i]){
                j++;
            }
        }

        return count;
    }
};
