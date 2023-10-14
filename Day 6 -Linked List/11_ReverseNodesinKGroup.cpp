/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

https://leetcode.com/problems/reverse-nodes-in-k-group/description/
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

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1)
            return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prevGroupEnd = dummy;
        ListNode* current = head;
        int count = 0;

        // Count the number of nodes in the list
        while (current != nullptr) {
            count++;
            current = current->next;
        }

        current = head;

        while (count >= k) {
            ListNode* groupStart = current;
            ListNode* groupEnd = current;

            // Move 'groupEnd' to the kth node in the group
            for (int i = 1; i < k && groupEnd != nullptr; i++) {
                groupEnd = groupEnd->next;
            }

            if (groupEnd != nullptr) {
                ListNode* nextGroupStart = groupEnd->next;
                groupEnd->next = nullptr; // Break the group

                // Reverse the current group and connect it to the previous group
                prevGroupEnd->next = reverseList(groupStart);
                groupStart->next = nextGroupStart;

                prevGroupEnd = groupStart;
                current = nextGroupStart;
                count -= k;
            } else {
                break;
            }
        }

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};