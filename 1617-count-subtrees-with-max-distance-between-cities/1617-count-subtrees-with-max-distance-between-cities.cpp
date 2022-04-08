class Solution {
public:
    int diameter( vector<vector<int>> &adj,vector<int> &vis,int cur,int &dia)
    {
        vis[cur]=1;
        
        int mx1=0,mx2=0;
        for(auto &i:adj[cur])
        {
            if(!vis[i])
            {
                int depth=(1+diameter(adj,vis,i,dia));
                if(depth>mx1)
                {
                    mx2=mx1;
                    mx1=depth;
                }
                else if(depth>mx2)
                {
                    mx2=depth;
                }
            }
            
        }
        
            dia=max(dia,mx1+mx2);
            return mx1;
        
    }
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<int> ans(n-1,0);
        
        for(int i=1;i<(1<<(n-1));i++)
        {
            
            vector<vector<int>> adj(n+1);
            for(int j=0;j<n-1;j++)
            {
                if((i&(1<<j)))
                {
                    adj[edges[j][0]].push_back(edges[j][1]);
                    adj[edges[j][1]].push_back(edges[j][0]);
                }
            }
            
            int cnt=0;
            vector<int> vis(n+1,0);
            int dia=-1;
            for(int j=1;j<=n;j++)
            {
                if(!vis[j] && adj[j].size()!=0)
                {
                   dia=max(dia,diameter(adj,vis,j,dia));
                   cnt++;
                }
            }
           // cout<<i<<" "<<dia<<endl;
            if(cnt==1)
                ans[dia-1]++;
        }
        return ans;
    }
};