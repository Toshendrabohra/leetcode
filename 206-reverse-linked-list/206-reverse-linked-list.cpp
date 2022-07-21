/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode * reverse(ListNode *head, ListNode *prev)
        {
            if (head->next == NULL)
            {   head->next = prev;
                return head;
            }

            ListNode *dum = reverse(head->next,head);
            head -> next = prev;
            
            return dum;
            
        }
    ListNode* reverseList(ListNode *head)
    {
        if(head == NULL)
            return NULL;

        return reverse(head, NULL);
    }
};