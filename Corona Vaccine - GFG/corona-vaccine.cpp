// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) 
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

 // } Driver Code Ends
//User function Template for C++

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
// 1 is for used
// 2 is for not used
int grand_childs(Node * root,vector<vector<int>> &dp)
{
    if(!root->left && !root->right)
    return 0;
    else if(!root->left)
    return min(dp[root->right->data][1],dp[root->right->data][0]);
    else if(!root->right)
    return min(dp[root->left->data][1],dp[root->left->data][0]);
    else
    return min(min(dp[root->right->data][1],dp[root->right->data][0]),min(dp[root->left->data][1],dp[root->left->data][0]));
}
int grand_child_taken(Node * root,vector<vector<int>> &dp)
{
    if(!root->left && !root->right)
    return 1e5+1;
    else if(!root->left)
    return dp[root->right->data][1];
    else if(!root->right)
    return dp[root->left->data][1];
    else
    return min(dp[root->right->data][1],dp[root->left->data][1]);
}
void dfs(Node * root,int par,vector<vector<int>> &dp)
{
    if(root==NULL)
    return ;
    dfs(root->left,root->data,dp);
    dfs(root->right,root->data,dp);
    
    if(root->left==NULL && root->right==NULL)
    {
        // supply
        dp[root->data][1]=1;
        //dp[par][0]=1;
    }
    else if(root->left==NULL)
    {
        //suppy
        dp[root->data][1]=min(min(dp[root->data][1],dp[root->right->data][1]),dp[root->right->data][0])+1;
        dp[root->data][1]=min(dp[root->data][1],grand_childs(root->right,dp)+1);
       // dp[par][0]=min(dp[par][0],dp[root->data][1]);
        
        dp[root->data][0]=min(dp[root->right->data][1],dp[root->data][0]);
        
    }
    else if(root->right==NULL)
    {
        dp[root->data][1]=min(min(dp[root->data][1],dp[root->left->data][1]),dp[root->left->data][0])+1;
        dp[root->data][1]=min(dp[root->data][1],grand_childs(root->left,dp)+1);
        //dp[par][0]=min(dp[par][0],dp[root->data][1]);
        
        dp[root->data][0]=min(dp[root->left->data][1],dp[root->data][0]);
    }
    else
    {
        //taking
        int right=min(dp[root->right->data][1],dp[root->right->data][0]);
            right=min(right,grand_childs(root->right,dp));
        int left=min(dp[root->left->data][1],dp[root->left->data][0]);
        left=min(left,grand_childs(root->left,dp)+1);
        dp[root->data][1]=left+right+1;
        //dp[par][0]=min(dp[par][0],dp[root->data][1]);
        //not taking
        //take right
        int take_right=dp[root->right->data][1];
        int not_left=min(dp[root->left->data][1],dp[root->left->data][0]);
        not_left=min(not_left,grand_child_taken(root->left,dp));
        dp[root->data][0]=min(dp[root->data][0],take_right+not_left);
        
        //take left
        int take_left=dp[root->left->data][1];
        int not_right=min(dp[root->right->data][1],dp[root->right->data][0]);
        not_right=min(not_right,grand_child_taken(root->right,dp));
        dp[root->data][0]=min(dp[root->data][0],take_left+not_right);
    }
   cout<<root->data<<" "<<dp[root->data][1]<<" "<<dp[root->data][0]<<endl;
}
class Solution{
public:
 int bfs(Node* root, unordered_map<Node*, int>& mp, int N){
        if(root){
            if(N == 4){
                if(mp.find(root) != mp.end()){
                    return mp[root];
                }
                int val1 = bfs(root -> left, mp, 1) 
                + bfs(root -> right, mp, 1);
                int val2 = bfs(root -> left, mp, 3) 
                + bfs(root -> right, mp, 4);
                if(root -> right != NULL){
                    val2++;
                }
                int val3 = bfs(root -> right, mp, 3) 
                + bfs(root -> left, mp, 4);
                if(root -> left != NULL){
                    val3++;
                }
                return mp[root] = min(val1, min(val2, val3));
            }
            else if(N == 3){
                int val1 = bfs(root -> left, mp, 1) 
                + bfs(root -> right, mp, 1);
                int val2 = bfs(root -> left, mp, 4) 
                + bfs(root -> right, mp, 1);
                int val3 = bfs(root -> left, mp, 1) 
                + bfs(root -> right, mp, 4);
                int val4 = bfs(root -> left, mp, 4) 
                + bfs(root -> right, mp, 4);
                if(root -> left != NULL){
                    val2++;
                    val4++;
                }
                if(root -> right != NULL){
                    val3++;
                    val4++;
                }
                return min(val1,min(val2,min(val3,val4)));
            }
            else if(N == 1){
                int val = 0;
                if(root -> left != NULL){
                    val += 1 + bfs(root -> left, mp, 4);
                }
                if(root -> right != NULL){
                    val += 1 + bfs(root -> right, mp, 4);
                }
                return val;
            }
        }
        return 0;
    }

    int supplyVaccine(Node* root){
        // Your code goes here
           unordered_map<Node*, int>mp;
        // map from node to number of
        // vaccines required to vaccinate 
        // the subtree rooted at node
        
        int val = bfs(root, mp, 4);
        mp[root] = val;
        if(root != NULL){
            mp[root]++;
        }
        return mp[root];
    }
};

// { Driver Code Starts.
int main() 
{
    int t;
    scanf("%d ", &t);
    while (t--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution ob;
        cout<<ob.supplyVaccine(root)<<"\n";
    }
    return 0;
}



  // } Driver Code Ends