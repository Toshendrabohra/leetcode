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
    ListNode* rotate(ListNode *head, int &cur, int k, ListNode *&thead)
    {
        
        if(head == NULL && k!=0)
            return thead;
        else if( head == NULL)
            return NULL;
        
        ListNode* temp = rotate(head->next, cur, k, thead);
        
        if(cur == k)
        {
            thead = temp;
            head->next = NULL;
        }
        else
            head->next = temp;
        
        cur++;
        
        return head;
        
        
    }
    int length(ListNode * head)
    {
        if(head == NULL)
            return 0;
        return 1 + length(head->next);
        
    }
    ListNode* rotateRight(ListNode* head, int k) {
        
        
        int n = length(head);
        int cur = 0;
        ListNode * thead = head;
        if(head == NULL || k%n == 0)
            return head;
        rotate(head, cur, k%n,thead);
        
       
        
        return thead;
    }
};