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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* curr = slow->next;
        ListNode *prev, *next;
        prev = slow->next = nullptr;
        while(curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* temp = head;
        while(temp != nullptr && prev != nullptr)
        {
            ListNode* n1 = temp->next;
            ListNode* n2 = prev->next;
            temp->next = prev;
            prev->next = n1;
            temp = n1;
            prev = n2;
        }
    }
};
