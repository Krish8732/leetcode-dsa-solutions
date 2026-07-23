// Leetcode: https://leetcode.com/problems/add-digits/
// Concepts: Math, Number Theory, Simulation

/*
Approach 1: Simulation
Repeatedly convert the number to string / sum its digits until a single digit remains.

T.C: O(log num)
S.C: O(log num) for string representation
*/

class Solution {
public:
    int addDigits(int num) {
        string n = to_string(num);
        while(n.length() > 1){
            int sum = 0;
            for (int i = 0; i < n.length(); i++){
                sum = sum + (n[i] - '0');
            }
            n = to_string(sum);
        }
        return stoi(n);
    }
};

/*
Approach 2: Digital Root Math Property (Optimal)
Intuition:
In base 10, any power of 10 leaves a remainder of 1 when divided by 9:
- 10 % 9 = 1
- 100 % 9 = 1
- 1000 % 9 = 1

For example: 38 = 3 * 10 + 8.
38 % 9 = (3 * 1 + 8) % 9 = (3 + 8) % 9 = 11 % 9 = 2.
Summing digits repeatedly does NOT change the remainder when divided by 9!

- If num == 0, the answer is 0.
- If num % 9 == 0, the single-digit result is 9 (e.g., 18 -> 1+8 = 9).
- Otherwise, the result is simply num % 9.

T.C: O(1)
S.C: O(1)
*/

class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        if (num % 9 == 0) return 9;
        return num % 9;
    }
};
