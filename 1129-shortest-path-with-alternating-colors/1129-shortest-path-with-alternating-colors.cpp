class Solution {
public:
    vector<int> bfs(int n, vector<vector<int>>& adj_red, vector<vector<int>>& adj_blue)
    {
        queue<vector<int>> q;
        q.push({0,0});
        q.push({0,1});
        vector<vector<int>> short_path(n,vector<int>(2,-1));
        short_path[0][0]=0;
        short_path[0][1]=0;
        // 0 ->red 
        // 1 ->blue
        while(!q.empty())
        {
            vector<int> cur=q.front();
            q.pop();
            if(cur[1]==0)
            {
            for(auto &i:adj_blue[cur[0]])
            {
                if(short_path[i][1]==-1)
                {
                    short_path[i][1]=short_path[cur[0]][0]+1;
                    q.push({i,1});
                }
               
            }
            }
            else
            {
                for(auto &i:adj_red[cur[0]])
            {
                if(short_path[i][0]==-1)
                {
                    short_path[i][0]=short_path[cur[0]][1]+1;
                    q.push({i,0});
                }
            }
            }
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            if(short_path[i][0]!=-1 && short_path[i][1]!=-1)
            ans[i]=min(short_path[i][0],short_path[i][1]);
            else if(short_path[i][0]!=-1)
            ans[i]=short_path[i][0];
            else
            ans[i]=short_path[i][1];
        }
        return ans;
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> adj_red(n),adj_blue(n);
        for(int i=0;i<redEdges.size();i++)
        {
            adj_red[redEdges[i][0]].push_back(redEdges[i][1]);
            //adj_red[redEdges[i][1]].push_back(redEdges[i][0]);
        }
        for(int i=0;i<blueEdges.size();i++)
        {
            adj_blue[blueEdges[i][0]].push_back(blueEdges[i][1]);
           // adj_blue[blueEdges[i][1]].push_back(blueEdges[i][0]);
        }
       return bfs(n,adj_red,adj_blue);   
    }
};