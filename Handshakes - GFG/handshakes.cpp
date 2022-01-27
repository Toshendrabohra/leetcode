// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int count(int N){
        // code here
        int dp[N+1];
        dp[0]=1;
        
        for(int i=2;i<=N;i+=2)
        {dp[i]=0;
          for(int j=2;j<=i;j+=2)
          {
              dp[i]+=dp[j-2]*dp[i-j];
          }
         // cout<<dp[i]<<" ";
        }
        return dp[N];
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
        cin>>N;
        Solution ob;
        cout << ob.count(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends