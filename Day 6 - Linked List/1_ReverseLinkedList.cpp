/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

https://leetcode.com/problems/reverse-linked-list/description/
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* p = nullptr;
        ListNode* q = head;
        ListNode* temp = head;

        while (q != nullptr) {
            temp = q->next;
            q->next = p;
            p = q;
            q = temp;
        }

        return p; // p now points to the new head of the reversed list
    }
};