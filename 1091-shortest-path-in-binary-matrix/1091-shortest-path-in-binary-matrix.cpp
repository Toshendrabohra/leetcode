class Solution {
public:
    bool poss(int x,int y,int &n,vector<vector<int>>& grid)
    {
        //cout<<x<<" "<<y<<endl;
        if(x>=0 && x<n && y>=0 && y<n && grid[x][y]==0)
            return true;
        return false;
    }
    int bfs(int &n,vector<vector<int>>& grid)
    {
        int dx[]={1,1,1,0,0,0,-1,-1,-1};
        int dy[]={-1,0,1,-1,0,1,-1,0,1};
        queue<vector<int>> q;
        if(grid[0][0]==0)
        q.push({0,0,1});
        grid[0][0]=-1;
        while(!q.empty())
        {
            vector<int>cur=q.front();
            if(cur[0]==n-1 && cur[1]==n-1)
                        return cur[2];
            q.pop();
            for(int i=0;i<9;i++)
            {
                if(poss(cur[0]+dx[i],cur[1]+dy[i],n,grid))
                {
                    
                    grid[cur[0]+dx[i]][cur[1]+dy[i]]=-1;
                    q.push({cur[0]+dx[i],cur[1]+dy[i],cur[2]+1});
                }
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //         cout<<grid[i][j]<<" ";
        //     cout<<endl;
        // }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
       int n = grid.size();

        queue<pair<int,int>> q;
        if(grid[0][0] || grid[n - 1][n - 1]) return -1;

        q.push({0,0});
        grid[0][0] = 1;

        int dx[] = {-1,1,0,0,-1,-1,1,1};
        int dy[] = {0,0,1,-1,-1,1,1,-1};

        while(q.size()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i = 0;i<8;i++){
                int x1 = x + dx[i];
                int y1 = y + dy[i];

                if(x1 >= 0 and y1 >= 0 and x1 < n and y1 < n and !grid[x1][y1]){
                    grid[x1][y1] = grid[x][y] + 1;
                    q.push({x1,y1});
                }
            }
        }

        return grid[n - 1][n - 1] ? grid[n - 1][n - 1] : -1;
    }
};