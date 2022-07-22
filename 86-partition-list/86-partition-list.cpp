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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dum = new ListNode, *temp = new ListNode();
        ListNode *dhead = temp, *ret = dum;
        
        while(head != NULL)
        {
            if( head -> val < x)
            {
                dum -> next = head;
                dum = dum->next;
                 head = head->next;
            }
            else
            {
                temp->next = head;
                temp = temp->next;
                head = head->next;
                temp->next = NULL;
            }
            
          
        }
        dum->next = dhead->next;
        return ret->next;
    }
};