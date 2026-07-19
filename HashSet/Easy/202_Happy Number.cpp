// LeetCode: https://leetcode.com/problems/happy-number/
// Concepts: Hash Table, Math, Two Pointers

// Approach: Use a hash set to keep track of the numbers we have already seen. If we encounter a number that is already in the set, it means we are in an infinite loop and the number is not happy. If we reach 1, then the number is happy.
// TC: O(log n) | SC: O(log n)

class Solution {
public:
       int sumofDigits(int n){
            int sum = 0;
        while(n>0){
             int d = n%10;
             n = n/10;
            sum = sum + d*d;
       }
        return sum;
       }
    bool isHappy(int n) {
       unordered_set<int> Seen;
       while ( n != 1 && !Seen.count(n)){
        Seen.insert(n);
        n = sumofDigits(n);
       }
       return n == 1;
    }
};
