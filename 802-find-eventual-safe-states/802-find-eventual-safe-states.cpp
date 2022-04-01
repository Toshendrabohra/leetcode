class Solution {
public:
    void dfs(int cur,vector<int> &vis,vector<int> &incycle,int &n,vector<vector<int>>& graph)
    {
        vis[cur]=1;
        for(auto &i:graph[cur])
        {
            if(!vis[i])
            dfs(i,vis,incycle,n,graph);
            else if(vis[i]==1)
            {
                incycle[i]=1;
            }
            incycle[cur]=incycle[i]|incycle[cur];
        }
        vis[cur]=2;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> incycle(n,0);
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        dfs(i,vis,incycle,n,graph);
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(!incycle[i])
                ans.push_back(i);
        }
        return ans;
    }
};