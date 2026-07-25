// LeetCode: https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/
// Concepts: Array, Two Pointers, Sorting

/*
Intuition:
We need to count pairs `(i, j)` with `0 <= i < j < n` such that `nums[i] + nums[j] < target`.

Approach 1: Brute Force (Nested Loops)
Check every pair `(i, j)` with `0 <= i < j < n` and increment `cnt` if `nums[i] + nums[j] < target`.
T.C: O(N^2)
S.C: O(1)

Approach 2: Optimal (Sorting + Two Pointers)
1. Sort `nums` in ascending order.
2. Initialize `l = 0` and `r = n - 1`.
3. If `nums[l] + nums[r] < target`, then because the array is sorted, any element between `l` and `r` paired with `nums[l]` will also satisfy `nums[l] + nums[k] < target`.
   - Add `(r - l)` to `cnt` and increment `l++`.
4. If `nums[l] + nums[r] >= target`, decrement `r--` since `nums[r]` is too large.

T.C: O(N log N) due to sorting.
S.C: O(1) auxiliary space.
*/

// Approach 1: Brute Force O(N^2)
class SolutionBruteForce {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] < target) cnt++;
            }
        }
        return cnt;
    }
};

// Approach 2: Optimal (Two Pointers) O(N log N)
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int cnt = 0;
        sort(nums.begin(), nums.end());

        while (l < r) {
            int left = nums[l];
            int right = nums[r];
            if (left + right < target) {
                cnt += r - l;
                l++;
            } else {
                r--;
            }
        }

        return cnt;
    }
};
