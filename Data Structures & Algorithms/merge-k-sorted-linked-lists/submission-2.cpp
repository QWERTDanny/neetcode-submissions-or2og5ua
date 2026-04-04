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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        int interval = 1;
        int k = lists.size();
        while(interval < k)
        {
            for(int i = 0; i+interval < k; i += interval*2)
            {
                lists[i] = mergeTwoLists(lists[i], lists[i+interval]);
            }
            interval *= 2;
        }
        return lists[0];
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                temp->next = l1;
                l1 = l1->next;
            }
            else
            {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        temp->next = (l1 ? l1 : l2);
        return dummy->next;
    }
};
