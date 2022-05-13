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
        Node* starting_node=root;
        
        while(starting_node)
        {
            Node* cur=new Node();
            if(starting_node->left != NULL)
                cur=starting_node->left;
            else if(starting_node->right != NULL)
                cur=starting_node->right;
    
            Node * temp=starting_node;
            starting_node=NULL;
            
            while(temp!=NULL)
            {
                if(temp->left!=NULL)
                {
                    cur->next=temp->left;
                    cur=cur->next;
                    
                    if(starting_node==NULL)
                        starting_node=cur;
                }
                if(temp->right!=NULL)
                {
                    cur->next=temp->right;
                    cur=cur->next;
                    
                    if(starting_node==NULL)
                        starting_node=cur;
                }
                
                temp=temp->next;
            }
            cur->next=NULL;
        }
        
        return root;
    }
};