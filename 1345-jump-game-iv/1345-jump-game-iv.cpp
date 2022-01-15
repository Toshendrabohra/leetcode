class Solution {
public:
    int bfs(int n,int source,vector<vector<int>> &adj,map<int,vector<int>> &comp,vector<int > &arr)
    {
        queue<int> q;
        q.push(0);
        int inf=1000001;
        vector<int> dis(n+1,inf);
        vector<int> vis(n+1,0);
        vis[source]=1;
        dis[source]=0;
        while(!q.empty())
        {
            int top=q.front();
            q.pop();
           
            for(auto &i:adj[top])
            {
                if(!vis[i])
                {   vis[i]=1;
                    q.push(i);
                    dis[i]=dis[top]+1;
                }
            }
          //  if(!comp[arr[top]].empty())
            {
            for(auto &i:comp[arr[top]])
            {
                if(i!=top && !vis[i])
                {
                    vis[i]=1;
                    q.push(i);
                    dis[i]=dis[top]+1;
                }
            }
            comp[arr[top]].clear();
            }
        }
        return dis[n-1];
    }
    int minJumps(vector<int>& arr) {
        int inf=1000001;
        map<int,vector<int>> comp;
        int n=arr.size();
        int cnt=1;
        for(int i=0;i<n;i++)
        {
            comp[arr[i]].push_back(i);
        }
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n;i++)
        {
            if(i<n-1)
            adj[i].push_back(i+1);
            
            if(i>0)
            adj[i].push_back(i-1);
        }
       return  bfs(n,0,adj,comp,arr);
    }
};