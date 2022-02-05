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
        ListNode *ans= new ListNode(-1);
        ListNode *head=ans;
        int k=lists.size();
        while(1)
        {
            ListNode *temp= new ListNode(100000);
            for(int i=0;i<k;i++)
            {
                if(lists[i]!=NULL)
                temp->val=min(temp->val,lists[i]->val);
            }
            if(temp->val==100000)
            { 
                ans=NULL;
                break;
            }
              for(int i=0;i<k;i++)
            {
                if(lists[i]!=NULL && lists[i]->val==temp->val)
                {
                    lists[i]=lists[i]->next;
                    break;
                }
            }
            ans->next=temp;
            ans=ans->next;
        }
        return head->next;
    }
};