// LeetCode: https://leetcode.com/problems/sequential-digits/
// Concepts: Math, Enumeration

/*
Approach 1 (Pre-computed / Direct Search): Generate all possible sequential digit numbers (since there are only 36 such numbers up to 123456789) and filter those that fall within the range [low, high].
TC: O(1) - The number of sequential digit numbers is fixed (36).
SC: O(1) - Constant space used for storing the predefined list.
*/

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        vector<int> allPossible = {
            12,      23,      34,      45,       56,       67,
            78,      89,      123,     234,      345,      456,
            567,     678,     789,     1234,     2345,     3456,
            4567,    5678,    6789,    12345,    23456,    34567,
            45678,   56789,   123456,  234567,   345678,   456789,
            1234567, 2345678, 3456789, 12345678, 23456789, 123456789};
        int n = allPossible.size();

        for (int i = 0; i < n; i++) {
            if (allPossible[i] < low)
                continue;
            if (allPossible[i] > high)
                break;
            result.push_back(allPossible[i]);
        }

        return result;
    }
};

/*
Approach 2 (Optimal BFS using Queue): Generate sequential numbers dynamically level-by-level using BFS. Start by queuing single digits 1 to 8. Pop each number, and if it's within [low, high], add it to results. If the last digit is less than 9, generate the next sequential number by multiplying by 10 and adding the next digit, then push it back into the queue.
TC: O(1) - The BFS tree has a maximum of 36 nodes.
SC: O(1) - The queue holds at most 8 elements at any time.
*/

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> que;
        vector<int> result;

        for (int i = 1; i < 9; i++) {
            que.push(i);
        }

        while (!que.empty()) {
            int num = que.front();
            que.pop();

            if (low <= num && num <= high)
                result.push_back(num);
            if (num > high)
                break;
            int lastDig = num % 10;
            if (lastDig == 9)
                continue;
            int newNum = num * 10 + (lastDig + 1);
            que.push(newNum);
        }

        return result;
    }
};
