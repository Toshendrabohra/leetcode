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
    Node * reverse (Node* head, Node* tail)
    {
        if( head == tail)
        {
            return tail;
        }
      Node* temp =  reverse(head -> next, tail);
        Node* temp1 =   head -> next -> next;
        head -> next -> next = head;
        head -> next = temp1;
        
        return temp;
    }
    Node* reverseBetween(Node* head, int m, int n)
    {
        //code here
        if( m == n)
        return head;
        Node* rhead = NULL,*s = head, *e = head, *ehead = NULL;
        int x = m - 1;
        
        while(x--)
        {
            rhead = s;
            s = s -> next;
        }
        
        x = n - 1;
        while(x--)
        {
            e = e->next;
        }
//ehead = e ->next;
        
        
       // cout<<s->ndata<<" ";
       if(rhead != NULL)
        rhead -> next = reverse(s,e);
        else
        return reverse(s,e);
        //cout<<rhead ->next ->data;
      //  s ->next = ehead;
        
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