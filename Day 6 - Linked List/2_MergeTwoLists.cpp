/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.


https://leetcode.com/problems/merge-two-sorted-lists/description/
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* current = dummyHead;

        ListNode* p = list1;
        ListNode* q = list2;

        while (p != nullptr && q != nullptr) {
            if (p->val <= q->val) {
                current->next = p;
                p = p->next;
            } else {
                current->next = q;
                q = q->next;
            }
            current = current->next;
        }

        if (p != nullptr) {
            current->next = p;
        }

        if (q != nullptr) {
            current->next = q;
        }

        ListNode* mergedList = dummyHead->next;
        delete dummyHead;
        return mergedList;
    }
};