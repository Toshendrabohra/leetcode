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
    ListNode* op (ListNode* head, int &n)
    {
        if(head == NULL)
            return NULL;
        head ->next =op(head -> next, n);
        n--;
        if(n == 0)
            return head -> next;
        else
            return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        return op(head,n);
    }
};