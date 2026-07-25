// LeetCode: https://leetcode.com/problems/convert-the-temperature/
// Concepts: Math

/*
Intuition:
We are given a non-negative floating-point number `celsius`.
We need to convert Celsius into Kelvin and Fahrenheit:
- Kelvin = Celsius + 273.15
- Fahrenheit = Celsius * 1.80 + 32.00

Return `{Kelvin, Fahrenheit}` as an array.

T.C: O(1)
S.C: O(1)
*/

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> ans;
        double kelvin = celsius + 273.15;
        double far = (celsius * 1.80) + 32.00;
        ans.push_back(kelvin);
        ans.push_back(far);
        return ans;
    }
};
