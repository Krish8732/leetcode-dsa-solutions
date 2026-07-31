// LeetCode: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/
// Concepts: Hash Table, String, Greedy, Sorting, Counting

/*
Intuition:
To minimize the total number of key presses needed to type the word, we should map the most frequently occurring characters to keys that require fewer presses (e.g., 1 push). Since a standard phone keypad has 8 available digit keys (2 through 9), the first 8 most frequent characters will take 1 push, the next 8 will take 2 pushes, the next 8 will take 3 pushes, and any remaining will take 4 pushes.

Approach:
1. Count the frequency of each lowercase character in `word` using a frequency array of size 26.
2. Sort the frequencies in descending order.
3. Iterate through the sorted frequencies and assign multiplier factors (`mul` = 1, 2, 3, 4) based on the rank/count of mapped characters.
4. Accumulate `frequency * mul` into total pushes.

T.C: O(N + K log K) = O(N) where N is the length of `word` and K = 26.
S.C: O(1) auxiliary space (fixed-size array of size 26).
*/

class Solution {
public:
    int minimumPushes(string word) {
        int arr[26] = {0};

        for (char c : word) {
            arr[c - 'a']++;
        }

        sort(arr, arr + 26, greater<int>());

        int pushes = 0;
        int cnt = 1;
        int mul = 1;

        for (int x : arr) {
            if (x == 0)
                break;

            pushes += x * mul;
            cnt++;

            // Note: Can also simplify multiplier calculation using index/count math:
            // e.g. pushes += (i / 8 + 1) * x (0-indexed) or (cnt - 1) / 8 + 1 (1-indexed)
            if (cnt > 8)
                mul = 2;
            if (cnt > 16)
                mul = 3;
            if (cnt > 24)
                mul = 4;
        }

        return pushes;
    }
};
