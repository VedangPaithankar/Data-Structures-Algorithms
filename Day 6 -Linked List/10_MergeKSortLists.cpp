/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

https://leetcode.com/problems/merge-k-sorted-lists/description/
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* dummyHead = new ListNode(-1);
        ListNode* current = dummyHead;

        ListNode* p = list1;
        ListNode* q = list2;

        while (p && q) {
            if (p->val <= q->val) {
                current->next = p;
                p = p->next;
            } else {
                current->next = q;
                q = q->next;
            }
            current = current->next;
        }

        if (p) {
            current->next = p;
        }

        if (q) {
            current->next = q;
        }

        ListNode* mergedList = dummyHead->next;
        delete dummyHead;
        return mergedList;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        
        while (lists.size() > 1) {
            ListNode* list1 = lists.back();
            lists.pop_back();
            ListNode* list2 = lists.back();
            lists.pop_back();
            ListNode* merged = mergeTwoLists(list1, list2);
            lists.push_back(merged);
        }
        
        return lists.front();
    }
};
