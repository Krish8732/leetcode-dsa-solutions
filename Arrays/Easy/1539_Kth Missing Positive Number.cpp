// LeetCode: https://leetcode.com/problems/kth-missing-positive-number/
// Concepts: Array, Binary Search

// Approach 1 (Brute Force):
// Intuition:
// Since the array is sorted, we can iterate through the array. For each element x, if x is less than or equal to k, it means one of the positive numbers less than or equal to x (which we expected to be missing) is actually present. Thus, we must shift our search range by incrementing k. If we find an element greater than k, we can stop early because all remaining elements will also be greater than k.
// TC: O(n) | SC: O(1)

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for ( int x : arr ){
            if ( x <= k ) k++;
            else break;
        }
        return k;
    }
};

// Approach 2 (Binary Search):
// Intuition:
// We can also return k + low at last. When we exit binary search the kth missing would be all numbers to the left plus the k numbers making up k + low (which is equivalent to k + high + 1).
// TC: O(log n) | SC: O(1)

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int msNo = arr[mid] - (mid + 1);
            if (msNo < k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return k + high + 1;
    }
};
