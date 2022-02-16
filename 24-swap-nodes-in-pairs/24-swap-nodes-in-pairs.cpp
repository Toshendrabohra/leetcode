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
    ListNode* swapPairs(ListNode* head) {
        ListNode *temp=new ListNode(-1);
        ListNode *newhead=temp;
        while(head!=NULL && head->next!=NULL)
        {
            cout<<head->val<<" ";
            temp->next=head->next;
            temp=temp->next;
            head->next=head->next->next;
            temp->next=head;
            temp=temp->next;
            head=head->next;
        }
        if(head!=NULL)
            temp->next=head;
        return newhead->next;
    }
};