// LeetCode: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
// Concepts: Array, Hash Table, Sorting, Counting, Prefix Sum

/*
Intuition & Approaches:

1. Sorting + Hash Map Approach:
   - Make a copy of `nums` and sort it.
   - For each element in the sorted array, its first occurrence index represents how many elements are strictly smaller than it. Store `sorted[copy[i]] = i` in a map.
   - Map original elements to their count values.
   - T.C: O(N log N) due to sorting.
   - S.C: O(N) extra space.

2. Optimized Frequency Array + Prefix Sum (O(N) Time, O(1) Auxiliary Space):
   - Since the constraints specify `0 <= nums[i] <= 100`, we can count frequencies using a fixed-size array of size 101.
   - Calculate prefix sums where `arr[i]` becomes the total count of elements `<= i`.
   - For any number `x > 0`, the count of elements strictly smaller than `x` is `arr[x - 1]`. For `x == 0`, it is `0`.

T.C: O(N + K) where N is the length of `nums` and K = 101. Overall O(N).
S.C: O(1) auxiliary space (excluding output array, fixed-size frequency array of size 101).
*/

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        int arr[101] = {0};

        for (int x : nums) {
            arr[x]++;
        }

        for (int i = 1; i < 101; i++) {
            arr[i] += arr[i - 1];
        }

        vector<int> result(n, 0);

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                result[i] = 0;
            else
                result[i] = arr[nums[i] - 1];
        }

        return result;
    }
};
