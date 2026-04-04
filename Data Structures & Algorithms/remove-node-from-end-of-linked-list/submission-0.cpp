/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        int length = 0;
        ListNode* temp = head;
        while(temp != nullptr) 
        {
            length++;
            temp = temp->next;
        }
        int steps = length - n;
        ListNode* prev = dummy;

        for(int i = 0; i < steps; i++)
        {
            prev = prev->next;
        }
        ListNode* del = prev->next;
        prev->next = del->next;
        delete del;

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
