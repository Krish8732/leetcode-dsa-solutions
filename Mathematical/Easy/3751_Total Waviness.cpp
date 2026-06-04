// Leetcode: Problem 3751
// Concepts: Math, Simulation, Digit Manipulation

// Approach: iterate over every number in the range, convert it to a string,
// and count waviness by checking whether each middle digit is a strict peak or valley.

// T.C: O(n)
// S.C: O(1)

class Solution {
public:
    int findWaviness(int num) {
        std::string s = std::to_string(num);
        int waviness = 0;

        for (int j = 1; j + 1 < (int)s.size(); j++) {
            char prev = s[j - 1];
            char curr = s[j];
            char next = s[j + 1];

            if (prev < curr && next < curr) {
                waviness++;
            }
            if (prev > curr && next > curr) {
                waviness++;
            }
        }

        return waviness;
    }

    int totalWaviness(int num1, int num2) {
        int result = 0;

        for (int num = num1; num <= num2; num++) {
            result += findWaviness(num);
        }

        return result;
    }
};