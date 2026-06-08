// LeetCode: https://leetcode.com/problems/partition-array-according-to-given-pivot/
// Concepts: Array, Two Pointers, Simulation

// Approach 1: Traverse the input array once to separate elements less than pivot, elements greater than pivot, and count the occurrences of pivot. Then reconstruct the array by copying elements less than pivot, then copying the pivot element equal count times, and then elements greater than pivot.
// TC: O(n) | SC: O(n)

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> lessThan;
        vector<int> greaterThan;
        int equal = 0;

        for (int x : nums) {
            if (x < pivot)
                lessThan.push_back(x);
            else if (x > pivot)
                greaterThan.push_back(x);
            else
                equal++;
        }

        int l = lessThan.size();
        int k = l + equal;

        for (int i = 0; i < n; i++) {
            if (i < l)
                nums[i] = lessThan[i];
            else if (i >= l && equal > 0) {
                nums[i] = pivot;
                equal--;
            } else {
                nums[i] = greaterThan[i - k];
            }
        }

        return nums;
    }
};

// Approach 2 (Optimal): Count the number of elements less than pivot, elements greater than pivot, and elements equal to pivot. Use these counts to determine the starting positions (indices) for less than (0), equal (lessThan), and greater than (lessThan + equal) elements in the result array. Then, traverse the input array and place each element directly in its corresponding position in the result array, incrementing the respective index pointers.
// TC: O(n) | SC: O(n)

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int lessThan = 0;
        int greaterThan = 0;
        int equal = 0;

        for (int x : nums) {
            if (x == pivot)
                equal++;
            else if (x < pivot)
                lessThan++;
            else
                greaterThan++;
        }

        int i = 0;
        int j = 0;
        int k = lessThan + equal;
        int l = lessThan;
        vector<int> result(n);

        while (i < n) {
            int curr = nums[i];
            if (curr < pivot) {
                result[j] = curr;
                j++;
            } else if (curr == pivot) {
                result[l] = curr;
                l++;
            } else {
                result[k] = curr;
                k++;
            }
            i++;
        }

        return result;
    }
};
