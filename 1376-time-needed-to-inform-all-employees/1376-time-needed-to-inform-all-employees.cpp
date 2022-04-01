class Solution {
public:
    int dfs(int cur,int &n, vector<int>& informTime,vector<vector<int>> &adj)
    {
        int x=0;
        for(auto &i:adj[cur])
        {
            x=max(x,dfs(i,n,informTime,adj)+informTime[cur]);
        }
        return x;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n;i++)
        {
            if(i!=headID)
            {
            adj[manager[i]].push_back(i);
            }
        }
        return dfs(headID,n,informTime,adj);
    }
};