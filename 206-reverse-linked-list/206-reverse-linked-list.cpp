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
    void reverse(ListNode *head, ListNode* prev, ListNode *&ans)
    {
        if(head == NULL)
            return ;
            
        //cout<<head->val<<" ";
       reverse(head -> next, head, ans);
       head ->next = prev;
      
        if(ans == NULL)
            ans = head;
        
    }
    ListNode* reverseList(ListNode* head) {
        
        ListNode * ans = NULL ;
        reverse(head,NULL,ans);
        return ans;
    }
};