// LeetCode: https://leetcode.com/problems/count-partitions-with-even-sum-difference/
// Concepts: Array, Math, Prefix Sum

// Approach 1 (Optimal Math Observation):
// Intuition:
// For any partition at index i, let the left sum be L and the right sum be R. The total sum is S = L + R.
// The difference is R - L = (S - L) - L = S - 2*L.
// The parity of the difference is (S - 2*L) % 2, which is equivalent to S % 2 because 2*L is always even.
// Therefore, the difference R - L is even if and only if the total sum S is even.
// If S is even, every possible partition (there are n - 1 partitions) will have an even difference. If S is odd, no partition will have an even difference.
// TC: O(n) | SC: O(1)

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ( sum % 2 == 0 ) return nums.size() - 1;
        else return 0; 
    }
};

// Approach 2 (Prefix Sum Simulation):
// Intuition:
// We compute the total sum of the array first. Then, we iterate through the array up to the second-to-last element, simulating each partition by maintaining a running left sum and subtracting the current element from the remaining right sum. For each partition, we check if the difference is even.
// TC: O(n) | SC: O(1)

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        int cnt = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            leftSum += nums[i];
            totalSum -= nums[i];
            if ((totalSum - leftSum) % 2 == 0)
                cnt++;
        }

        return cnt;
    }
};
