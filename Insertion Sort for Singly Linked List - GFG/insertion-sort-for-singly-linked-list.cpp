// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}




 // } Driver Code Ends
//User function Template for C++

/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* insertionSort(struct Node* head)
    {
        //code here
        
        //Node *glprev=head;
         Node *temp=head;
        while(temp!=NULL)
        {
           
           // int cnt=0;
           //cout<<temp->data<<" "<<endl;
            while(temp->next!=NULL &&  temp->data <= temp->next->data)
            {
              //  cout<<temp->data<<" ";
                temp=temp->next;
                
            }
            if(temp->next!=NULL)
            {
                
                Node* dum=temp->next;
                temp->next=temp->next->next;
                Node* tempo=head;
                Node* prev=NULL;
                while(tempo->data<dum->data)
                {
                    prev=tempo;
                    tempo=tempo->next;
                }
                if(prev==NULL)
                {
                    head=dum;
                }
                else
                {
                    prev->next=dum;
                }
                dum->next=tempo;
            }
            else
            {
                break;
            }
            
        }
        return head;
    }
};

// { Driver Code Starts.
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

        Solution ob;

		head = ob.insertionSort(head);
		printList(head);

		cout << "\n";



	}
	return 0;
}  // } Driver Code Ends