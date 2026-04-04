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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* gp = dummy;

        while(true)
        {
            ListNode* kth = getKth(gp, k);
            if(!kth) break;

            ListNode* gn = kth->next;
            ListNode* prev = kth->next;
            ListNode* curr = gp->next;

            while(curr != gn)
            {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            ListNode* temp = gp->next;
            gp->next = kth;
            gp = temp;
        }
        return dummy->next;
    }

    ListNode* getKth(ListNode* curr, int k)
    {
        while(curr && k > 0)
        {
            curr = curr->next;
            k--;
        }
        return curr;
    }
};
