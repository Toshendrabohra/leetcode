// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs( vector<vector<int>> &adj, int cur, vector<int> &dis)
    {
        dis[cur]=1;
        
        for( auto i:adj[cur])
        {
            if(dis[i] == -1)
            dfs(adj, i, dis);
            
            dis[cur]=max(dis[cur], 1 + dis[i]);
        }
        
        
    }
    int minColour(int n, int m, vector<int> mat[]) {
        // code here 
        vector<vector<int>> adj(n+1);
        
        for( int i = 0; i<m ; i++)
        {
            adj[mat[i][1]].push_back(mat[i][0]);
        }
        
        vector<int> dis( n+1, -1);
        
        int ans=0;
        
        for( int i =1 ; i <= n ;i++)
        {
            if(dis[i] == -1)
            dfs(adj, i, dis);
            ans=max(ans, dis[i]);
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M, x, y;
        cin>>N>>M;
        vector<int> mat[M];
        for(int i = 0;i < M;i++){
            cin>>x>>y;
            mat[i].push_back(x);
            mat[i].push_back(y);
        }
        
        Solution ob;
        cout<<ob.minColour(N, M, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends