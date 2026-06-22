// LeetCode: https://leetcode.com/problems/angle-between-hands-of-a-clock/
// Concepts: Mathematical, Geometry

// Approach: Calculate the position of the hour hand and the minute hand in degrees from 12 o'clock. The hour hand moves 30 degrees per hour plus 0.5 degrees per minute. The minute hand moves 6 degrees per minute. Return the minimum of absolute difference and 360 minus that difference.
// TC: O(1) | SC: O(1)

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hr = 30 * hour;
        double mini = 6 * minutes;

        hr += 0.5 * minutes;
        double val = abs(hr - mini);

        return (min(val, 360 - val));
    }
};
