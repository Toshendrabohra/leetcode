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
        
        ListNode* rhead = l1;
        
        int carry = 0;
        ListNode* prev = NULL;
        while(l1 != NULL && l2  != NULL)
        {
            carry = (carry + l1->val + l2->val);
            l1 -> val = carry % 10;
            carry /= 10;
          
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1 != NULL)
        {
            carry = (carry + l1->val );
            l1 -> val = carry % 10;
            carry /= 10;
          
            prev = l1;
            l1 = l1->next; 
        }
        
        while(l2 != NULL)
        {   carry = (carry + l2->val);
            ListNode * dum = new ListNode();
            dum -> val = (carry)%10;
            prev -> next = dum;
            prev = prev -> next;
            carry /= 10;

            l2 = l2->next;
        }
          
        if(carry)
        {
            ListNode * dum = new ListNode();
            dum -> val = (carry )%10;
            prev ->next = dum;
         
        }
        return rhead;
    }
};