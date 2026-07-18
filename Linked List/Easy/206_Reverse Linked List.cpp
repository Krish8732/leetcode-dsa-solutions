// LeetCode: https://leetcode.com/problems/reverse-linked-list/
// Concepts: Linked List, Recursion

// Approach 1 (Iterative): Traverse the list and change the next pointer of each node to point to its previous node.
// TC: O(n) | SC: O(1)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while (temp != NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }
};

// Approach 2 (Recursive): Recursively reverse the rest of the list, then point the next node's next back to the current head, and set the current head's next to NULL.
// TC: O(n) | SC: O(n) due to recursion stack space

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* last = reverseList(head->next);

        head->next->next = head; // next node pointing back to curr
        head->next = NULL;       // removing old link

        return last;
    }
};
