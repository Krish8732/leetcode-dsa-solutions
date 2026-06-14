// LeetCode: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
// Concepts: Linked List, Two Pointers, Stack

// Approach 1 (Vector): Convert the linked list into an array/vector. Then use two pointers (one at the beginning, one at the end) to sum the twins and find the maximum sum.
// TC: O(n) | SC: O(n)

class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> nums;
        ListNode* curr = head;
        while (curr) {
            nums.push_back(curr->val);
            curr = curr->next;
        }

        int i = 0, j = nums.size() - 1;
        int maxSum = 0;
        while (i < j) {
            maxSum = max(maxSum, nums[i] + nums[j]);
            i++, j--;
        }

        return maxSum;
    }
};

// Approach 2 (Stack): Traverse the linked list and push all node values onto a stack. Then traverse the first half of the linked list again, comparing and summing elements with the values popped from the stack (which gives elements from the end).
// TC: O(n) | SC: O(n)

class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int> st;
        ListNode* curr = head;
        while (curr) {
            st.push(curr->val);
            curr = curr->next;
        }

        int n = st.size();
        int maxSum = 0;
        curr = head;

        for (int i = 1; i <= n / 2; i++) {
            int val1 = curr->val;
            int val2 = st.top();
            st.pop();
            maxSum = max(maxSum, val1 + val2);
            curr = curr->next;
        }

        return maxSum;
    }
};

// Approach 3 (Reverse Second Half - Optimal): Find the middle of the linked list using slow and fast pointers. Reverse the second half of the linked list. Then, traverse both halves simultaneously using two pointers to find the maximum twin sum.
// TC: O(n) | SC: O(1)

class Solution {
public:
    int pairSum(ListNode* head) {
        // step 1
        ListNode *slow = head, *fast = head;
        while (fast && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // step 2

        ListNode *prev, *curr;
        prev = NULL, curr = slow;
        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr; // or prev = curr;
            curr = temp;
        }

        ListNode* temp = head;
        int maxSum = 0;

        // step 3

        while (prev) {
            int val1 = temp->val, val2 = prev->val;
            maxSum = max(maxSum, val1 + val2);
            temp = temp->next;
            prev = prev->next;
        }

        return maxSum;
    }
};
