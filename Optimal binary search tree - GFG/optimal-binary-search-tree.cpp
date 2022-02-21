// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int optimalSearchTree(int keys[], int freq[], int n)
    {       
        // code here
       
      
    
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
        dp[i][j]=INT_MAX;
     for(int len=1;len<=n;len++)
     {
         for(int start=0;start<n-len+1;start++)
         {
             int sum=0;
             for(int i=start;i<start+len;i++)
             sum+=freq[i];
             for(int root=start;root<start+len;root++)
             {
                 int l,r;
                 if(root==start)
                 l=0;
                 else
                 l=dp[start][root-1];
                 if(root==start+len-1)
                 r=0;
                 else
                 r=dp[root+1][start+len-1];
       //          cout<<l<<" "<<r<<" ";
                 dp[start][start+len-1]=min(dp[start][start+len-1],l+r+sum);
             }
          //   cout<<dp[start][start+len-1]<<" "<<sum<<endl;
         }
       // cout<<endl;
     }
     return dp[0][n-1];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        int keys[n];
        for(int i=0;i<n;i++)cin>>keys[i];
        int freq[n];
        for(int i=0;i<n;i++)cin>>freq[i];
        Solution ob;
        cout<<ob.optimalSearchTree(keys, freq, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends