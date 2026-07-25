// LeetCode: https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/
// Concepts: Math, Arithmetic Progression

/*
Intuition:
We are given two positive integers `n` and `m`.
- `num1`: sum of all integers in [1, n] that are NOT divisible by `m`.
- `num2`: sum of all integers in [1, n] that ARE divisible by `m`.
We need to return `num1 - num2`.

Approach 1: Brute Force (Iterate 1 to n)
Loop `i` from 1 to `n`. Add `i` to `num1` if `i % m != 0`, else add to `num2`. Return `num1 - num2`.
T.C: O(N)
S.C: O(1)

Approach 2: Better (Loop only through multiples of m)
Compute total sum from 1 to n as `totalSum = n * (n + 1) / 2`.
Loop `temp = m` up to `n` in steps of `m` to accumulate `num2`.
Then `num1 = totalSum - num2`, return `num1 - num2`.
T.C: O(N / M)
S.C: O(1)

Approach 3: Most Optimal (O(1) Math)
Notice that `num2` is the sum of multiples of `m`: `m + 2m + 3m + ... + k*m = m * (1 + 2 + ... + k)`, where `k = n / m`.
Using sum of first `k` integers formula: `divSum = m * (k * (k + 1)) / 2`.
Since `num1 = totalSum - divSum`, the required result `num1 - divSum` simplifies to `totalSum - 2 * divSum`.
T.C: O(1)
S.C: O(1)
*/

// Approach 1: Brute Force O(N)
class SolutionBruteForce {
public:
    int differenceOfSums(int n, int m) {
        int div = 0;
        int notdiv = 0;
        for (int i = 1; i <= n; i++) {
            if (i % m != 0) {
                div += i;
            } else {
                notdiv += i;
            }
        }
        return div - notdiv;
    }
};

// Approach 2: Better - Loop through multiples O(N / M)
class SolutionBetter {
public:
    int differenceOfSums(int n, int m) {
        int totalSum = (n * (n + 1)) / 2;
        int num2 = 0;
        int temp = m;

        while (temp <= n) {
            num2 += temp;
            temp += m;
        }

        int num1 = totalSum - num2;
        return num1 - num2;
    }
};

// Approach 3: Most Optimal - Pure Math O(1)
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int totalSum = (n * (n + 1)) / 2;
        int divCnt = n / m;

        int divSum = m * (divCnt * (divCnt + 1)) / 2;

        return totalSum - (2 * divSum);
    }
};
