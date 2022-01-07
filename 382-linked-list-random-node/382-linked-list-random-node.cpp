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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

std::mt19937 gen_{std::random_device{}()};
class Solution {
public:
    ListNode* dum;
    int n;
    Solution(ListNode* head) {
        dum=head;
       n=0;
        while(dum!=NULL)
        {
            n++;dum=dum->next;
        }
        dum=head;
    }
    
    int getRandom() {
  int  cur=uniform_int_distribution<int>(0,n-1)(rng);
        ListNode * temp=dum;
        for(int i=0;i<cur;i++)
        {
            temp=temp->next;
        }
        cur++;
        return  temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */