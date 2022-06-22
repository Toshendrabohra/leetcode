/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node* , Node *> m;
        
        Node* dum = head;
        Node* nhead = new Node(0);
        Node* chead = nhead;
        while(dum)
        {
            Node * temp = new Node(dum->val);
            nhead->next = temp;
            nhead = nhead->next;
            m[dum] = nhead;
            dum = dum->next;
        }
        
        dum = head;
        nhead = chead->next;
        
        while(dum)
        {
            nhead->random = m[dum->random];
            dum = dum->next;
            nhead = nhead->next;
        }
        
        return chead->next;
    }
};