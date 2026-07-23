// Leetcode: https://leetcode.com/problems/guess-number-higher-or-lower/
// Concepts: Binary Search, Interactive

/*
Intuition:
Use binary search between search range 1 and n.
Call the API guess(mid):
- If guess(mid) == 0: mid is the target number.
- If guess(mid) == 1: target is higher than mid, search right half (l = mid + 1).
- If guess(mid) == -1: target is lower than mid, search left half (r = mid - 1).

T.C: O(log n)
S.C: O(1)
*/

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
