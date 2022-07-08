// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mcm(int p[], int n, vector<vector<int>> &dp, int l, int r)
    {
        if(r-l <= 1)    
        return 0;
        if(dp[l][r]!=-1)
        return dp[l][r];
        
        int x = INT_MAX;
        
        for( int i = l+1; i < r; i++)
        {
            x = min(x, p[l]*p[r]*p[i]+ mcm(p,n,dp,l,i) + mcm(p,n,dp,i,r));
            cout<<l<<" "<<r<<" "<<x<<endl;
        }
        
        
        return dp[l][r] = x;
    }
    
    string matrixChainOrder(int a[], int n){
        // code here
        vector<vector<int>> dp(n+1, vector<int>(n,0));
        vector<vector<string>> str(n+1,vector<string> (n+1));
        for(int gap = 1; gap<n ; gap++)
        {
            
            for(int i = 0; i < n - gap; i++)
            {   if(gap==1)
                    {
                        str[i][i+gap] = 'A'+i;
                        continue;
                    }
                int x = INT_MAX;
                for(int j = i+1; j < i+gap ; j++)
                {
                    int cost = dp[i][j]+dp[j][i+gap] + a[i]*a[j]*a[i+gap];
                    if(x> cost)
                    {
                        x = cost;
                        str[i][i+gap] = '('+str[i][j]+str[j][i+gap]+')';
                        dp[i][i+gap] = x;
                    }
                }
                
                
            }
        }
        
        return str[0][n-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends