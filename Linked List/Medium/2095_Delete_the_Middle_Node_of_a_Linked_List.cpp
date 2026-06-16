// LeetCode: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
// Concepts: Linked List, Two Pointers

// Approach: Use two pointers (slow and fast) to locate the middle node. By keeping a prev pointer, we can modify the links to skip (and delete) the middle node (slow) once the fast pointer reaches the end.
// TC: O(n) | SC: O(1)

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next)
            return NULL;

        ListNode *slow = head, *fast = head;
        ListNode* prev = NULL;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        slow->next = NULL;
        delete slow;

        return head;
    }
};
