class Solution {
public:
    int cnt=0;
    void dfs(int cur,int &n,vector<vector<vector<int>>> &adj,vector<int> &vis)
    {
    
    
    for(auto &i:adj[cur])
    {
        if(!vis[i[0]])
        {
            vis[cur]=1;
        cnt+=i[1];
            dfs(i[0],n,adj,vis);
        }
    }
    
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<vector<int>>> adj(n);
        cnt=0;
        for(int i=0;i<n-1;i++)
        {
            adj[connections[i][0]].push_back({connections[i][1],1});
            adj[connections[i][1]].push_back({connections[i][0],0});
        }
        vector<int> vis(n,0);
        vis[0]=1;
             dfs(0,n,adj,vis);
        return cnt;
    }
};