// Leetcode: https://leetcode.com/problems/contains-duplicate/
// Concepts: Array, Hash Table

/*
Intuition:
Traverse through the array while storing elements in a hash set. 
If an element is already present in the hash set, a duplicate exists, so return true.
Otherwise, insert the element and continue. If the loop finishes, all elements are unique.

T.C: O(n)
S.C: O(n)
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(int x : nums){
            if (seen.count(x)) return true;
            seen.insert(x);
        }
        return false;
    }
};
