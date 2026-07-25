// LeetCode: https://leetcode.com/problems/count-operations-to-obtain-zero/
// Concepts: Math, Euclidean Algorithm, Recursion

/*
Intuition:
Given two non-negative integers `num1` and `num2`, in one operation:
- If `num1 >= num2`, subtract `num2` from `num1`.
- Otherwise, subtract `num1` from `num2`.
Return the number of operations needed to make either `num1 = 0` or `num2 = 0`.

Approach 1: Brute Force (Repeated Subtraction)
Subtract the smaller number from the larger number step by step until one becomes 0.
T.C: O(max(num1, num2)) in worst case.
S.C: O(1)

Approach 2: Optimal Iterative (Euclidean Division)
Repeated subtraction is equivalent to integer division `a / b` and remainder `a % b`.
Using `cnt += num1 / num2; num1 %= num2; swap(num1, num2);` operates like the Euclidean algorithm for GCD.
T.C: O(log(min(num1, num2)))
S.C: O(1)

Approach 3: Optimal Recursive (Euclidean Division)
Recursive version of Euclidean division.
T.C: O(log(min(num1, num2)))
S.C: O(log(min(num1, num2))) call stack.
*/

// Approach 1: Brute Force (Repeated Subtraction)
class SolutionBruteForce {
public:
    int countOperations(int num1, int num2) {
        int cnt = 0;
        while (num1 != 0 && num2 != 0) {
            if (num1 >= num2) {
                num1 -= num2;
            } else
                num2 -= num1;
            cnt++;
        }
        return cnt;
    }
};

// Approach 2: Optimal Iterative (Euclidean Division)
class Solution {
public:
    int countOperations(int num1, int num2) {
        int cnt = 0;
        while (num1 > 0 && num2 > 0) {
            cnt += num1 / num2;
            num1 %= num2;
            swap(num1, num2);
        }
        return cnt;
    }
};

// Approach 3: Optimal Recursive (Euclidean Division)
class SolutionRecursive {
public:
    int countOperations(int num1, int num2) {
        if (num1 == 0 || num2 == 0) {
            return 0;
        }

        if (num2 > num1) {
            swap(num1, num2);
        }

        return num1 / num2 + countOperations(num1 % num2, num2);
    }
};
