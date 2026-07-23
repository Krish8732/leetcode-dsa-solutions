// Leetcode: https://leetcode.com/problems/intersection-of-two-arrays/
// Concepts: Array, Hash Table, Two Pointers, Binary Search, Sorting

/*
Approach 1: Hash Set Lookup (Optimal)
Intuition:
Store all elements of nums1 in an unordered_set for O(1) average lookup.
Iterate through nums2; if an element exists in the set, add it to the result and erase it 
from the set to prevent duplicates.

T.C: O(m + n)
S.C: O(m)
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> result;

        for (int x : nums2){
            if (s.count(x)){
                result.push_back(x);
                s.erase(x);
            }
        }
         
        return result;
    }
};

/*
Approach 2: Sorting + Two Pointers
Intuition:
Sort both arrays. Use two pointers (i for nums1, j for nums2) to scan both arrays simultaneously.
Store current values num1 = nums1[i] and num2 = nums2[j] for readability.
- If num1 == num2, add to res (if not already added as the last element) and advance both i and j.
- Otherwise, advance the pointer pointing to the smaller element.

T.C: O(m log m + n log n)
S.C: O(1) auxiliary space (excluding output array)
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0;
        int j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            int num1 = nums1[i];
            int num2 = nums2[j];

            if (num1 == num2) {
                if (res.empty() || res.back() != num1) {
                    res.push_back(num1);
                }
                i++;
                j++;
            } else if (num1 < num2) {
                i++;
            } else {
                j++;
            }
        }
        return res;
    }
};
