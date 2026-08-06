// LeetCode: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
// Concepts: Array, Bit Manipulation, Sorting

/*
Approach 1 (Transform and Sort - Simulation):
Intuition:
We iterate through the array and count the number of set bits (1s) for each element using Brian Kernighan's algorithm.
Brian Kernighan's algorithm uses `num = num & (num - 1)` which clears the lowest set bit in each step, executing in O(k) steps where k is the number of set bits.
We store pairs of {bitCount, originalNumber} in a temporary vector, sort it (which naturally sorts by bitCount first, and then by value in case of ties), and reconstruct the original array.
TC: O(n * log(n) + n * log(max_val)) | SC: O(n)
*/

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> bitCnts;
        for (int& num : arr) {
            int temp = num;
            int bitCnt = 0;
            while (num > 0) {
                num = num & (num - 1);
                bitCnt++;
            }
            bitCnts.push_back({bitCnt, temp});
        }

        sort(bitCnts.begin(), bitCnts.end());

        arr.clear();

        for (auto& it : bitCnts) {
            arr.push_back(it.second);
        }

        return arr;
    }
};

/*
Approach 2 (Custom Sort using Lambda - Space Optimized):
Intuition:
Instead of creating an auxiliary vector of pairs, we can sort the original array in-place.
We define a custom comparator (via a lambda function) that compares two integers based on:
1. Their count of set bits (determined via a helper method or built-in functions).
2. Their numerical value (as a tie-breaker).
Using the custom comparator directly in `std::sort` optimizes the space complexity to O(1) (excluding standard sort recursion space).
TC: O(n * log(n) * log(max_val)) | SC: O(1) (in-place)
*/

class Solution2 {
public:
    static int findSetBits(int n) {
        int cnt = 0;
        while (n > 0) {
            cnt++;
            n &= (n - 1);
        }
        return cnt;
    }

    vector<int> sortByBits(vector<int>& arr) {

        auto comp = [](const int& num1, const int& num2) {
            int setBitCnt1 = findSetBits(num1);
            int setBitCnt2 = findSetBits(num2);
            if (setBitCnt1 == setBitCnt2)
                return num1 < num2;
            else
                return setBitCnt1 < setBitCnt2;
        };

        sort(arr.begin(), arr.end(), comp);

        return arr;
    }
};
