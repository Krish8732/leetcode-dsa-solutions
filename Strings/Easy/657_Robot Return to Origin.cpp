// LeetCode: https://leetcode.com/problems/robot-return-to-origin/
// Concepts: String, Simulation

/*
Intuition:
Simulate the movement of the robot on a 2D coordinate grid starting at (0, 0).
- 'L' decreases y-coordinate, 'R' increases y-coordinate
- 'U' decreases x-coordinate, 'D' (else) increases x-coordinate
After processing all moves, check if the robot has returned to origin (x == 0 && y == 0).

T.C: O(N) where N is the length of moves string
S.C: O(1)
*/

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;
        for (char &c : moves){
            if (c == 'L')   y--;
            else if (c == 'R')   y++;
            else if (c == 'U') x--;
            else x++;
        }

        return (x == 0 && y == 0);
    }
};
