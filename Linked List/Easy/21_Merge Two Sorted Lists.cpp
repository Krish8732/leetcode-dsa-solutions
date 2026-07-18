// LeetCode: https://leetcode.com/problems/merge-two-sorted-lists/
// Concepts: Linked List, Recursion

// Approach 1 (Recursive): Compare the head of both lists. The smaller value node becomes the root, and its next is set to the result of recursively merging the rest of the lists.
// TC: O(n + m) | SC: O(n + m) due to recursion stack space

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* result;

        if (list1->val < list2->val){
            result = list1;
            result->next = mergeTwoLists(list1->next, list2);
        } else {
            result = list2;
            result->next = mergeTwoLists(list1, list2->next);
        }

        return result;
    }
};

// Approach 2 (Iterative): Use a dummy node and a tail pointer. Iterate through both lists, appending the node with the smaller value to the tail, and advance the corresponding list pointer. Finally, append any remaining elements of the non-empty list.
// TC: O(n + m) | SC: O(1)

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }

            tail = tail->next;
        }

        if (!list1) {
            tail->next = list2;
        } else {
            tail->next = list1;
        }

        return dummy->next;
    }
};
