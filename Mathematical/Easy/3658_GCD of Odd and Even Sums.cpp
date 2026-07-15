// LeetCode: https://leetcode.com/problems/gcd-of-odd-and-even-sums/
// Concepts: Math, Number Theory

/* 
Approach 1 (Brute Force): Calculate the sum of the first n odd numbers and the first n even numbers up to 2n, then compute their GCD.
TC: O(n) | SC: O(1)
*/

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddSum = 0;
        int evenSum = 0;
        for (int i = 1; i <= 2*n; i++){
            if (i % 2 == 0){
                evenSum += i;
            } else {
                oddSum += i;
            }
        }

        return gcd(evenSum, oddSum);
    }
};

/* 
Approach 2 (Optimal): The sum of the first n odd numbers is n^2, and the sum of the first n even numbers is n * (n + 1).
Their GCD is gcd(n^2, n*(n+1)) = n * gcd(n, n+1) = n * 1 = n (since consecutive numbers are coprime).
TC: O(1) | SC: O(1)
*/

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return n;
    }
};
