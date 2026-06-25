// LeetCode: https://leetcode.com/problems/count-subarrays-with-majority-element-i/
// Concepts: Array, Prefix Sum, Boyer-Moore Voting Algorithm
// Approach: Brute force checks all subarrays using Boyer-Moore Voting Algorithm. Optimal approach uses prefix sum of target occurrences to check the majority condition for each subarray.
// TC: O(n^2) | SC: O(n)

// Brute Force - 
// using moore's voting alg to find majority element in every subarray 

class Solution {
public:
    int findMajorElem(vector<int>& nums, int i, int j) {
        int candid = -1;
        int vote = 0;
        int start = i, end = j;

        while (i <= j) {
            if (vote != 0 && nums[i] == candid) {
                vote++;
            } else if (vote != 0 && nums[i] != candid) {
                vote--;
            } else if (vote == 0) {
                candid = nums[i], vote = 1;
            }
            i++;
        }

        int cnt = 0;
        int l = end - start + 1;

        while (start <= end) {
            if (nums[start] == candid)
                cnt++;

            start++;
        }

        if (cnt <= l / 2)
            return -1;

        return candid;
    }

    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (findMajorElem(nums, i, j) == target)

                    cnt++;
            }
        }

        return cnt;
    }
};

// Optimal Soln - 

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> pre(n, 0);

        if (nums[0] == target)
            pre[0] = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] == target) {
                pre[i] = 1;
                pre[i] += pre[i - 1];
                continue;
            }
            pre[i] += pre[i - 1];
        }

        int subArrayCnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int l = j - i + 1;
                int cnt = pre[j] - ((i > 0) ? pre[i - 1] : 0);
                if (cnt > l / 2)
                    subArrayCnt++;
            }
        }

        return subArrayCnt;
    }
};

