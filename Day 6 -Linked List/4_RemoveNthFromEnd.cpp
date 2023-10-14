/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

https://leetcode.com/problems/remove-nth-node-from-end-of-list/
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* iter = head;
        int x = 0; 
        while (iter) { 
            iter = iter->next;
            x++;
        }

        if (x == n) {
            return head->next;
        }

        iter = head; 
        int y = 0; 
        while (y < x - n - 1 && iter->next) {
            iter = iter->next;
            y++;
        }

        if (iter->next) { 
            ListNode* temp = iter->next;
            iter->next = temp->next;
            delete temp; 
        }

        return head;
    }
};
