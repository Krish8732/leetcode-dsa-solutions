// Leetcode: https://leetcode.com/problems/summary-ranges/
// Concepts: Array

/*
Intuition:
Traverse the sorted array to find consecutive ranges where adjacent elements differ by 1.
- Track the start of the current range in lastNum.
- When nums[i] - nums[i - 1] > 1, the consecutive range ends at nums[i - 1].
- If lastNum == nums[i - 1], format as "a", otherwise format as "a->b".
- Update lastNum = nums[i] to start the next range.
- After the loop finishes, format and append the final remaining range.

T.C: O(n)
S.C: O(1) auxiliary space
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return {};
        int lastNum = nums[0];
        vector<string> ranges;
        for (int i = 1; i < n; i++) {
            if ((long long)nums[i] - nums[i - 1] > 1) {
                if (nums[i - 1] == lastNum)
                    ranges.push_back(to_string(lastNum));
                else
                    ranges.push_back(to_string(lastNum) + "->" +
                                     to_string(nums[i - 1]));
                lastNum = nums[i];
            }
        }

        if (lastNum == nums[n - 1])
            ranges.push_back(to_string(lastNum));
        else {
            ranges.push_back(to_string(lastNum) + "->" +
                             to_string(nums[n - 1]));
        }

        return ranges;
    }
};
