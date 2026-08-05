// LeetCode: https://leetcode.com/problems/count-of-matches-in-tournament/
// Concepts: Math, Simulation

// Approach 1 (Simulation):
// Intuition:
// We simulate the tournament round by round. In each round, if n is even, there are n / 2 matches and n / 2 teams advance. If n is odd, there are (n - 1) / 2 matches and (n / 2) + 1 teams advance. We repeat this until only 1 team is left.
// TC: O(log n) | SC: O(1)

class Solution {
public:
    int numberOfMatches(int n) {
        int matches = 0;
        while ( n > 1){
           if ( n % 2 == 0){
            matches += n / 2;
            n /= 2;
           }
           else {
            matches += (n-1) / 2;
            n = n/2 + 1;
           }
        }
        return matches;
    }
};

// Approach 2 (Optimal Math Observation):
// Intuition:
// In a single-elimination tournament, every match eliminates exactly one team. Since there are n teams and only 1 winner at the end, exactly n - 1 teams must be eliminated. Therefore, there must be exactly n - 1 matches played in total.
// TC: O(1) | SC: O(1)

class Solution {
public:
    int numberOfMatches(int n) {
        return n - 1;
    }
};
