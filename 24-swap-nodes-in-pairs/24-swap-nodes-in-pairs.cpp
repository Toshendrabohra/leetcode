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
    ListNode* modified(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* temp=new ListNode(-1) ;
        temp=head->next;
         ListNode* dum=head->next->next;
        temp->next=head;
        temp->next->next=modified(dum);
        return temp;
    }
    ListNode* swapPairs(ListNode* head) {
        return modified(head);
    }
};