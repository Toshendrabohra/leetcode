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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* nhead = new ListNode();
        ListNode* rhead = nhead;
        
        int carry = 0;
        while(l1 != NULL && l2!= NULL)
        {
            int x = (carry + l1->val + l2->val)/10;
            ListNode * dum = new ListNode();
            dum -> val = (carry + l1->val + l2->val)%10;
            nhead ->next = dum;
         
            carry = x;
            nhead = nhead ->next;
            l1 = l1->next;
            l2 = l2->next;
            
            
        }
        
        while(l1 != NULL)
        {
         int x = (carry + l1->val)/10;
            ListNode * dum = new ListNode();
            dum -> val = (carry + l1->val )%10;
            nhead ->next = dum;
         
            carry = x;
            nhead = nhead ->next;
            l1 = l1->next;
           // l2 = l2->next;
            
        }
        
        while(l2 != NULL)
        {int x = (carry + l2->val)/10;
            ListNode * dum = new ListNode();
            dum -> val = (carry + l2->val )%10;
            nhead ->next = dum;
         
            carry = x;
            nhead = nhead ->next;
          //  l1 = l1->next;
            l2 = l2->next;
        }
          
        if(carry)
        {
            ListNode * dum = new ListNode();
            dum -> val = (carry )%10;
            nhead ->next = dum;
         
          
        }
        return rhead->next;
    }
};