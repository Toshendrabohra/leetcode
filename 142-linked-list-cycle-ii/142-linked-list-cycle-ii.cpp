/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * slow=head,*fast=head;
        while(slow!=NULL && fast!=NULL)
        {
            slow=slow->next;
            if(fast->next==NULL)
                return NULL;
            fast=fast->next->next;
            if(fast==slow)
                break;
        }
        if(fast==NULL)
            return NULL;
        slow=head;
        while(slow!=fast)
        {
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};