// Leetcode: https://leetcode.com/problems/contains-duplicate-ii/
// Concepts: Array, Hash Table, Sliding Window

/*
Intuition:
Maintain a sliding window of size k using a hash set.
For each element:
1. If the element is already in the set, a duplicate within distance k is found, return true.
2. Insert the current element into the set.
3. If the set size exceeds k, remove the element that fell out of the window (at index i - k).

T.C: O(n)
S.C: O(min(n, k))
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_set<int> Seen;
        for ( int i = 0; i<nums.size(); i++){
            if( Seen.count(nums[i])) return true;
            Seen.insert(nums[i]);
            if (Seen.size() > k) Seen.erase(nums[i-k]);
        }
        return false;
    }
};
