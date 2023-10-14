/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

https://leetcode.com/problems/linked-list-cycle/description/
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> address; // Use an unordered_set with ListNode* as keys
        ListNode *temp = head;

        while (temp != nullptr) {
            // If we find the same node's address in the set, it means there's a cycle
            if (address.find(temp) != address.end()) {
                return true;
            }

            // Otherwise, add the node's address to the set and move to the next node
            address.insert(temp);
            temp = temp->next;
        }

        // If we reach the end of the list without finding a cycle, return false
        return false;
    }
};