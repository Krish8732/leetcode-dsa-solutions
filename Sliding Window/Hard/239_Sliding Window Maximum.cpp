// Leetcode: https://leetcode.com/problems/sliding-window-maximum/
// Concepts: Array, Queue, Sliding Window, Monotonic Queue

// Approach: Use a deque to maintain a monotonic decreasing queue of indices. For each element, remove indices out of the current window from the front, remove indices of elements smaller than the current element from the back, push the current index, and append the element at the front to the result once the window size k is reached.

// T.C: O(n)
// S.C: O(k)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> result;
        for (int i = 0; i < n; i++) {
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1)
                result.push_back(nums[dq.front()]);
        }

        return result;
    }
};
