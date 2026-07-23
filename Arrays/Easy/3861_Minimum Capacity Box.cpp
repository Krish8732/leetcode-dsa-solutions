// Leetcode: https://leetcode.com/problems/minimum-capacity-box/
// Concepts: Array

/*
Intuition:
Iterate through the capacity array to find a box that can hold the item (capacity[i] >= itemSize) 
with the smallest capacity possible (capacity[i] < minCapacity).

- Initialize minCapacity = INT_MAX and idx = -1.
- In a single pass, if capacity[i] >= itemSize and capacity[i] < minCapacity, update minCapacity and idx.
- If multiple boxes have the same minimum capacity, keeping strict inequality (<) automatically 
  preserves the smallest 0-based index.

T.C: O(n)
S.C: O(1)
*/

class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n = capacity.size();
        int minCapacity = INT_MAX;
        int idx = -1;
        for (int i = 0; i < n; i++){
            if (capacity[i] >= itemSize && capacity[i] < minCapacity){
                minCapacity = capacity[i];
                idx = i;
            }
        }

        return idx;
    }
};
