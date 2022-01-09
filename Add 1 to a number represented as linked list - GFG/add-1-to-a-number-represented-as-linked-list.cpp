// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node* temp=head;
        if(head==NULL)
        return head;
        if(head->next==NULL)
        {
            if(head->data!=9)
            {
               head->data++;
            }
            else
            {Node* dum=new Node(1);
            head->data=0;
                dum->next=head;
                head=dum;
            }
            return head;
        }
        Node *prev=new Node(-1);
        while(temp!=NULL)
        {
            if(temp->data!=9)
            {
                prev=temp;
            }
            temp=temp->next;
        }
        if(prev->data==-1)
        {
            prev->data=0;
            prev->next=head;
            head=prev;
            while(prev!=NULL)
            {
                prev->data=(prev->data+1)%10;
                prev=prev->next;
            }
            
        }
        else
        {
            while(prev!=NULL)
            {
                prev->data=(prev->data+1)%10;
                prev=prev->next;
            }
        }
        return head;
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends