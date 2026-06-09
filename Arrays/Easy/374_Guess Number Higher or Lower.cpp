// LeetCode: https://leetcode.com/problems/guess-number-higher-or-lower/
// Concepts: Binary Search, Interactive

// Approach: Use simple binary search to guess the number.

// TC: O(log n) | SC: O(1)

class Solution {
public:
    int guessNumber(int n) {
        int l = 1 , r = n;
        while (l <= r){
            int mid = l + (r-l)/2;
            if (guess(mid) == 0) return mid;
            else if (guess(mid) == 1) l = mid + 1;
            else  r = mid - 1;
        }

        return 1;
    }
};
