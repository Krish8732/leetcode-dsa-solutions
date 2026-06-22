// LeetCode: https://leetcode.com/problems/find-the-highest-altitude/
// Concepts: Arrays, Prefix Sum

// Approach: Traverse the gain array, keep a running sum of the altitude, and maintain the maximum altitude reached so far.
// TC: O(n) | SC: O(1)

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int runningSum = 0;
        int maxH = 0;
        for (int g : gain){
            runningSum += g;
            maxH = max(maxH, runningSum);
        }

        return maxH;
    }
};
