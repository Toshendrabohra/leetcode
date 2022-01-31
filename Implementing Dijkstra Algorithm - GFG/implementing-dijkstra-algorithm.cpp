// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
        p.push({0,S});
        int inf=INT_MAX;
        vector<int> dis(V+1,inf);
        dis[S]=0;
        vector<int> vis(V+1,0);
        vector<vector<pair<int,int>>> neib(V+1);
        
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
            neib[i].push_back({adj[i][j][0],adj[i][j][1]});
            //neib[adj[i][1]].push_back({adj[i][0],adj[i][2]});
            }
        }
        while(!p.empty())
        {
            pair<int,int> dum=p.top();
            p.pop();
            if(vis[dum.second])
            continue;
            vis[dum.second]=1;
            for(auto &i:neib[dum.second])
            {
                if(dis[dum.second]+i.second<dis[i.first])
                {
                    dis[i.first]=dis[dum.second]+i.second;
                    p.push({dis[i.first],i.first});
                }
            }
        }
        return dis;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends