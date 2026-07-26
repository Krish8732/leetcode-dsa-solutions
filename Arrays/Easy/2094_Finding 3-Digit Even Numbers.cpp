// LeetCode: https://leetcode.com/problems/finding-3-digit-even-numbers/
// Concepts: Array, Hash Table, Enumeration, Sorting

/*
Intuition:
We need to find all unique 3-digit even numbers that can be formed using digits from the input array.

Approach 1: Brute Force (3-Loop Permutations + Set)
Iterate over all unique index triplets (i, j, k) such that:
- digits[i] != 0 (no leading zeros)
- digits[k] % 2 == 0 (must be even)
Insert formed numbers into a set to ensure uniqueness and sorted order.
T.C: O(N^3) where N is the length of digits array.
S.C: O(N^3) space for set to store results.

Approach 2: Optimal Frequency Map Iteration over Candidate Even Numbers
Instead of forming numbers from digits, iterate over all valid 3-digit even numbers [100, 998] with step 2:
For each number, check if its digit counts can be satisfied by the frequency map of the input `digits` array.
Because range [100, 998] is fixed, iterations are constant (450 numbers).
T.C: O(N) to build frequency map + O(1) loop operations.
S.C: O(1) space since digit frequency arrays are fixed size 10.
*/

// Approach 1: Brute Force (Index Permutations + Set)
class SolutionBruteForce {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> res;
        int n = digits.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (i == j || j == k || k == i) continue;
                    if (digits[i] == 0) continue;
                    if (digits[k] % 2 != 0) continue;
                    res.insert((digits[i] * 100) + (digits[j] * 10) + (digits[k]));
                }
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};

// Approach 2: Optimal Frequency Map Iteration
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> count(10, 0);
        for (int d : digits) {
            count[d]++;
        }

        vector<int> result;

        for (int num = 100; num < 1000; num += 2) {
            vector<int> currCount(10, 0);
            int temp = num;

            while (temp > 0) {
                currCount[temp % 10]++;
                temp /= 10;
            }

            bool valid = true;
            for (int i = 0; i < 10; i++) {
                if (currCount[i] > count[i]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                result.push_back(num);
            }
        }

        return result;
    }
};
