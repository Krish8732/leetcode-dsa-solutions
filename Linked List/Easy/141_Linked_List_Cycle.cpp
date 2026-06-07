// LeetCode: https://leetcode.com/problems/linked-list-cycle/
// Concepts: Linked List, Two Pointers

// Approach: Use Floyd's Cycle Detection algorithm with slow and fast pointers. If a cycle exists, the pointers will eventually meet at the same node.

// TC: O(n) | SC: O(1)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }

        return false;
    }
};
