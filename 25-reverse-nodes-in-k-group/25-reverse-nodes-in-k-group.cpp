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
        ListNode* reverse(ListNode *head, int k, int cur, int &flag)
        {
            cur++;
            if(head->next == NULL)
            {
                if(cur != k)
                    flag = 0;
                return head;
            }
            ListNode* temp = reverse(head->next, k, cur%k, flag);
            if(cur == k)
                flag = 1;
            
            if(cur!=k && flag)
            {
                ListNode* dum = head->next;
                head->next = head->next->next;
                dum->next = head;
                return temp;
            }
            else
                head->next = temp;
            
            return head;
            
        }
        ListNode* reverseKGroup(ListNode *head, int k)
        {
            int flag = 1;

            return reverse(head, k, 0,flag);
        }
};