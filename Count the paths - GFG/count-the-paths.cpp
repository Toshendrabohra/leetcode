// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    void dfs(int cur, int d, vector<vector<int>> &graph, vector<int> &dp)
    {
        if(cur == d)
        {
            dp[cur] = 1;
            return ;
        }
        dp[cur] = 0;
        
        for(  auto &i: graph[cur])
        {
            if(dp[i] == -1)
            {
                dfs(i, d, graph, dp);
            }
            dp[cur] += dp[i];
        }
        
    }
    
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    // Code here
	    vector<vector<int>> graph(n);
	    
	    for( int i = 0; i < edges.size(); i++)
	    {
	        graph[edges[i][0]].push_back(edges[i][1]);
	    }
	    
	    vector<int> dp(n, -1);
	    
	    dfs(s, d, graph, dp);
	    
	    return dp[s];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends