class Solution {
public:
    struct node
    {
        int v;
        int dist;
        
    };
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<node>> graph(n+1);
        
        for(int i =0 ; i < times.size() ; i++)
        {
            node temp;
            temp.v=times[i][1];
            temp.dist=times[i][2];
            graph[times[i][0]].push_back(temp);
        }
        
        vector<int> dist (n+1,-1);
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>> > dij;
        
        dist[k]=0;
        vector<int> temp = {0,k};
        dij.push(temp);
        
        while(!dij.empty())
        {
            vector<int> dtop=dij.top();
            dij.pop();
            
            if(dist[dtop[1]] < dtop[0])
                continue;
                
            
            for( auto &i : graph[dtop[1]])
            {
                if(dist[i.v]==-1 || (dist[i.v] > dist[dtop[1]] + i.dist ))
                {
                    dist[i.v] = dist[dtop[1]] + i.dist;
                    dij.push({dist[i.v] , i.v});
                }
            }
        }
        
        int ans=-1;
        
        for(int i=1 ; i<= n ; i++ )
        {
            if(dist[i]==-1)
                return -1;
            ans=max(ans,dist[i]);
        }
        
        return ans;
    }
};