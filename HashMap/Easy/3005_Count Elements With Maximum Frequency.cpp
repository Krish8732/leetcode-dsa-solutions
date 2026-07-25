// LeetCode: https://leetcode.com/problems/count-elements-with-maximum-frequency/
// Concepts: Array, Hash Table, Counting

/*
Intuition:
We want to find the total frequencies of all elements that have the maximum frequency in `nums`.

1. Build a frequency map `freq` counting occurrences of each element in `nums`.
2. Iterate through each key-value pair `p` in `freq`:
   - If `p.second > maxVal`, we found a new maximum frequency! Reset `sum = 0` to discard all previous lower-frequency sums.
   - Update `maxVal = max(maxVal, p.second)`.
   - If `maxVal == p.second`, add `maxVal` (or `p.second`) to `sum`.
3. Return `sum`.

T.C: O(N) where N is the length of `nums`.
S.C: O(N) space for the frequency map.
*/

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }
        int maxVal = INT_MIN;
        int sum = 0;
        int cnt = 0;
        for (auto& p : freq) {
            if (p.second > maxVal)
                sum = 0;
            maxVal = max(maxVal, p.second);
            if (maxVal == p.second) {
                sum += maxVal;
            }
        }

        return sum;
    }
};
