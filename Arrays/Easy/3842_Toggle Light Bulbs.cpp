// Leetcode: https://leetcode.com/problems/toggle-light-bulbs/
// Concepts: Array, Hash Table, Bit Manipulation

/*
Intuition:
We are given a list of light bulb toggles. Each occurrence of a bulb index flips its state between ON and OFF.

Initial Approach (HashMap):
- Use an `unordered_map<int, bool>` to track each bulb's state.
- Toggle state on each occurrence.
- Collect all keys with state `true` into a vector and sort.
T.C: O(n log n)
S.C: O(n)

Optimized Approach (Direct Array Indexing):
- Find `maxElem` in `bulbs`.
- Use a boolean vector `vec` of size `maxElem + 1` initialized to `false`.
- For each `bulb`, toggle `vec[bulb] = !vec[bulb]`.
- Iterate through `vec` from index 1 to `maxElem` and push indices with `true` values directly into `result` (maintaining sorted order naturally).
T.C: O(n + maxElem)
S.C: O(maxElem)
*/

class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        int maxElem = *max_element(bulbs.begin(), bulbs.end());
        vector<bool> vec(maxElem + 1, false);

        for (int bulb : bulbs) {
            vec[bulb] = !(vec[bulb]);
        }

        vector<int> result;
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i]) result.push_back(i);
        }

        return result;
    }
};
