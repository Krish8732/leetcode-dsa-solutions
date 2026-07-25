// LeetCode: https://leetcode.com/problems/apple-redistribution-into-boxes/
// Concepts: Array, Greedy, Sorting

/*
Intuition:
Calculate total apples across all packs, sort capacity in descending order, and take boxes greedily until totalApples is covered.

T.C: O(N + M log M) where N is apple.size() and M is capacity.size()
S.C: O(1)
*/

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApples = accumulate(apple.begin(), apple.end(), 0);
        int m = capacity.size();
        sort(capacity.begin(), capacity.end(), greater<int>());
        for (int i = 0; i < m; i++) {
            totalApples -= capacity[i];
            if (totalApples <= 0) {
                return i + 1;
            }
        }
        return 0;
    }
};
