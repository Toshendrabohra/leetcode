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
    ListNode* reverse(ListNode * head, int cnt, ListNode *prev)
    {
        if(cnt <= 1 || head == NULL)
        {   
            //head -> next = prev;
            return head;
        }
        
        ListNode* dum = reverse(head->next, cnt - 1,head);
        ListNode* temp = head->next->next;
        head -> next ->next = head;
        head ->next = temp;
        
        return dum;
        
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int cnt = 0;
    ListNode *dum = head;
        while(left > 2)
        {
            head = head -> next;
            left--;
            right--;
        }
        if(left == 1)
            return reverse(head,right , NULL);
        head ->next = reverse(head->next, right -1,head);
        
        return dum;
    }
};