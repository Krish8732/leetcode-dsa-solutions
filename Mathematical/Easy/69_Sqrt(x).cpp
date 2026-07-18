// LeetCode: https://leetcode.com/problems/sqrtx/
// Concepts: Math, Binary Search

// Approach (Binary Search): Search for the square root in the range [0, x]. Use binary search to find the largest integer mid such that mid * mid <= x.
// TC: O(log x) | SC: O(1)

class Solution {
public:
    int mySqrt(int x) {
        long long low = 0, high = x;
        while(low <= high){
            long long mid = low+(high - low)/2;
              if (mid*mid == x ) return (int)mid;
              if (mid*mid < x ){
                low = mid + 1;
              }
              else{
                high = mid - 1;
              }
        }
        return (int)high;
    }
};
