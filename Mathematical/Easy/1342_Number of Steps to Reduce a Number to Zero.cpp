// LeetCode: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
// Concepts: Math, Bit Manipulation

// LeetCode: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
// Concepts: Math, Bit Manipulation

/*
Approach 1 (Simulation):
Intuition:
We simulate the process directly.
If the number is even, we divide it by 2.
If the number is odd, we subtract 1 from it.
We repeat this process until the number becomes 0, counting the number of operations.
TC: O(log(num)) | SC: O(1)
*/

class Solution {
public:
    int numberOfSteps(int num) {
        int cnt = 0;
        while (num > 0) {
            if (num % 2 == 0) {
                num /= 2;
            } else {
                num--;
            }
            cnt++;
        }
        return cnt;
    }
};

/*
Approach 2 (Bitwise Operations):
Intuition:
We can examine the binary representation of the number.
For the least significant bit:
- If it is 1 (odd), we need to subtract 1 (to make it 0) and then divide by 2 (shift right). This takes 2 operations.
- If it is 0 (even), we only need to divide by 2 (shift right). This takes 1 operation.
We can loop through the bits using bitwise shift `num >>= 1`.
Since the most significant bit (the leading 1) only needs to be subtracted (1 step) and not shifted again after becoming 0,
our count will overestimate by 1 step at the end. Thus we return `cnt - 1` for any non-zero input.
TC: O(log(num)) | SC: O(1)
*/

class Solution2 {
public:
    int numberOfSteps(int num) {
        if (!num)
            return 0;
        int cnt = 0;
        while (num > 0) {
            cnt += (num & 1) ? 2 : 1;
            num >>= 1;
        }
        return cnt - 1;
    }
};
