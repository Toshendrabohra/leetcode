// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    void dfs(vector<int> adj[], bool &poss, int x, vector<int> &vis)
    {
        for(auto &i:adj[x])
        {
            if(vis[i] == -1)
            {
                vis [i] = 1 - vis[x];
                dfs(adj, poss, i, vis);
            }
            else if( vis[i] == vis[x])
            {
                poss = false;
            }
        }
    }
	bool isBipartite(int n, vector<int>adj[]){
	  
	    bool poss = true;
	    vector<int> vis(n+1,-1);
	    for(int i = 0; i < n; i++)
	    {
    	    if( vis[i] == -1)  
    	    {
    	        vis[i] = 1;
    	        dfs(adj , poss, i, vis);
    	    }
	    }
	    
	    return poss;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends