/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;
        Node * temp=root;
        while(temp->left!=NULL)
        {
            Node * tempo=temp->left;
              tempo->next=temp->right;
                tempo=tempo->next;
            Node * dum=temp->next;
            while(dum!=NULL)
            {
            tempo->next=dum->left;
            tempo=tempo->next   ;
                    tempo->next=dum->right;
                tempo=tempo->next;
                dum=dum->next;
            }
            tempo->next=NULL;
            temp=temp->left;
        }
        return root;
    }
};