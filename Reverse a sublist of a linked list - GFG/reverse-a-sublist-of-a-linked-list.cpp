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
  Node* reverse(Node* temp, int n, Node* prev){
       Node* temp1 = new Node(temp->data);
       temp1->next = prev;
       if(n==0){
           return temp1;
       }
       return reverse(temp->next,n-1,temp1);
   }
    Node* reverseBetween(Node* head, int m, int n)
    {
     Node *main_temp=head,*prev_node=NULL,*temp=NULL;

       n -= m;
       m--;
       while(m--){
           prev_node = main_temp;
           main_temp = main_temp->next;
       }

       temp = reverse(main_temp, n, NULL);
       
       if(prev_node != NULL)
           prev_node->next = temp;
       else
           head = temp;
       
       while(temp->next!=NULL){
           main_temp = main_temp->next;
           temp = temp->next;
       }
       
       temp->next = main_temp->next;
       
       return head;
    }
};

// { Driver Code Starts.

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



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
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

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}
  // } Driver Code Ends