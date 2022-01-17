// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
     struct node{
        node*children[26];
        bool isend;
        
    };
    
void insert(node*root,string x)
{
    for(int i=0;i<x.size();i++)
    {
        if(root->children[x[i]-'a']==NULL)
        {
            node*temp=new node();
            root->children[x[i]-'a']=temp;
        }
        
        root=root->children[x[i]-'a'];
    }
    root->isend=1;
    
    return;
    
}
    
    bool search(node*root, string s)
    {
        for(int i=0;i<s.size();i++)
        {
            if(root->children[s[i]-'a']==NULL)return 0;
            
            root=root->children[s[i]-'a'];
            
        }
        
        // cout<<s<<endl;
        if(root->isend)return 1;
        return 0;
    }
    
        
        bool pallin(string s)
        {
            // return 1;
            int i=0;
            int j=s.size()-1;
            
            while(i<=j)
            {
                if(s[i]==s[j])
                {
                    i++;
                    j--;
                }
                else
                {
                    return 0;
                }
            }
            
            return 1;
            
        }
        
        struct comp{
        bool operator ()(string x, string y)
        {
            return x.length()>y.length();
        }
        };
    bool palindromepair(int N, string arr[]) {
        // code here
         vector<string>pq(N);
        for(int i=0;i<N;i++)
        {
            pq[i]=arr[i];
        }
        sort(pq.begin(),pq.end(),comp());
        for(int i=0;i<N;i++)
        {
            arr[i]=pq[i];
        }
        node*root= new node();
    
        
        
        for(int j=0;j<N;j++)
        {
            if(search(root,arr[j]))return 1;
                
                
            string orig=arr[j];
            
            //check from ahead
            for(int i=0;i<arr[j].size();i++)
            {
                string x= arr[j].substr(0,i+1);
                string w= x;
                reverse(w.begin(),w.end());
                
                string z= arr[j]+w;
                
                if(pallin(z))
                {
                    insert(root,w);
                }
            }
            for(int i=0;i<arr[j].size();i++)
            {
                string x= arr[j].substr(i);
                string w=x;
                 reverse(w.begin(),w.end());
                 
                 string z= w+arr[j];
                 if(pallin(z))
                {
                    insert(root,w);
                }
                 
            }
            
            
            
            //insert all possibilities 
        }
        
        return 0;
        
    }

};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        string arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.palindromepair(N, arr) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends