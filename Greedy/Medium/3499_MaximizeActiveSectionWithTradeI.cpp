// LeetCode: https://leetcode.com/problems/maximize-active-section-with-trade-i/
// Concepts: Greedy, String

// Approach 1: Count all '1's, extract sizes of all contiguous blocks of '0's, and find the maximum sum of two adjacent blocks of '0's.
// TC: O(N) | SC: O(N)

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int onesCnt = count(begin(s), end(s), '1');
        int i = 0;

        vector<int> inactiveBlocks;

        while (i < n) {
            if (s[i] == '0') {
                int start = i;
                while (i < n && s[i] == '0')
                    i++;
                inactiveBlocks.push_back(i - start);
            } else {
                i++;
            }
        }

        int maxBlockSize = 0;

        for (int i = 1; i < inactiveBlocks.size(); i++) {
            maxBlockSize =
                max(maxBlockSize, inactiveBlocks[i - 1] + inactiveBlocks[i]);
        }

        return maxBlockSize + onesCnt;
    }
};
