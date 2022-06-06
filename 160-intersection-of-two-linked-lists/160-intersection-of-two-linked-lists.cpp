/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode(int x) : val(x), next(NULL) {}
 *};
 */
class Solution
{
    public:
        ListNode* getIntersectionNode(ListNode *headA, ListNode *headB)
        {

            int n1 = 0, n2 = 0;
            ListNode *temp1 = headA, *temp2 = headB;
            
            while (temp1 != NULL)
            {
                n1++;
                temp1 = temp1->next;
            }
            
            while (temp2 != NULL)
            {
                n2++;
                temp2 = temp2->next;
            }
            
            temp1 = headA;
            temp2 = headB;
            
            while (n1 > n2)
            {
                temp1 = temp1->next;
                n1--;
            }
            while (n2 > n1)
            {
                temp2 = temp2->next;
                n2--;
            }
            
            while (temp1 != NULL && temp2 != NULL)
            {
                if(temp1 == temp2)
                    return temp1;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            
            
            return NULL;
        } 
    
};