// Leetcode: https://leetcode.com/problems/number-of-unique-xor-triplets-ii/
// Concepts: Bit Manipulation, Hash Table, Array

/*
Intuition:
We need to find the number of unique XOR sum values resulting from picking 3 elements (triplets) from `nums`.

Approach 1 (Brute Force using unordered_set):
- Compute all pair XOR combinations `nums[i] ^ nums[j]` for `0 <= i <= j < n` and store them in an `unordered_set<int> pairXor`.
- For each unique pair XOR in `pairXor`, XOR with every element `x` in `nums` and insert into `unordered_set<int> tripletXor`.
- Return `tripletXor.size()`.
T.C: O(n^2 + |pairXor| * n)
S.C: O(|pairXor| + |tripletXor|)

Approach 2 (Optimized Bit/Boolean Frequency Array):
- Compute all unique pairwise XOR values and store boolean presence in vector `s1` of size `T`, where `T` is the smallest power of 2 strictly greater than `max(nums)`.
- For each reachable pair XOR value `i` in `s1`, XOR it with each element `nums[j]` to set reachable triplet XOR boolean flags in `s2`.
- Count total `true` entries in `s2`.
T.C: O(n^2 + T * n)
S.C: O(T)
*/

// Approach 1: Brute Force using unordered_set
class SolutionHashSet {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> pairXor;
        unordered_set<int> tripletXor;

        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
                pairXor.insert(nums[i] ^ nums[j]);
            }
        }

        for (auto &val : pairXor){
            for (int &x : nums){
                tripletXor.insert(val ^ x);
            }
        }

        return tripletXor.size();
    }
};

// Approach 2: Optimized using boolean frequency vectors
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int maxElem = *max_element(begin(nums), end(nums));

        int T = 1;
        while (T <= maxElem){
            T <<= 1;
        }

        vector<bool> s1(T, false);
        vector<bool> s2(T, false);

        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
                int val = nums[i] ^ nums[j];
                s1[val] = true;
            }
        }

        for (int i = 0; i < T; i++){
            if (s1[i]){
                for (int j = 0; j < n; j++){
                    s2[i ^ nums[j]] = true;
                }
            }
        }

        int tripletCount = 0;

        for (bool check : s2){
            if (check) tripletCount++;
        }

        return tripletCount;
    }
};
