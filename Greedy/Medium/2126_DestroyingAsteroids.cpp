// LeetCode: https://leetcode.com/problems/destroying-asteroids/
// Concepts: Greedy, Sorting
    
// Approach: using greedy and optimising using early return cause if mass of planet becomes more than max val an ast can have, its guaranteed to be true further
    
// T.C: O(N log N).
// S.C: O(1)

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {

        sort(begin(asteroids), end(asteroids));

        for (int ast : asteroids) {
            if (ast > mass) {
                return false;
            } else if (mass >= 1e5) {
                return true;
            }
            mass += ast;
        }

        return true;
    }
};