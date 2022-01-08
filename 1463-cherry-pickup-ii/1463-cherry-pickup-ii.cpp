class Solution {
public:
    bool valid(int x,int y,int &n,int &m)
    {
        if(x>=0 && x<n && y<m && y>=0)
            return true;
        return false;
    }
    int dfs(int rx,int r1y,int r2y,int &n,int &m,vector<vector<vector<int>>> &dp,vector<int> &dy,vector<vector<int>>& grid)
    {
        if(dp[rx][r1y][r2y]!=-1)
            return dp[rx][r1y][r2y];
        int mx=0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(valid(rx+1,r1y+dy[i],n,m) && valid(rx+1,r2y+dy[j],n,m))
                {
                    mx=max(mx,grid[rx+1][r1y+dy[i]]+(( r1y+dy[i]==r2y+dy[j])?0:grid[rx+1]                      [r2y+dy[j]]+dfs(rx+1,r1y+dy[i],r2y+dy[j],n,m,dp,dy,grid)));
                }
            }
        }
         return dp[rx][r1y][r2y]=mx;   
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        vector<int > dy={-1,0,1};
       return grid[0][0]+grid[0][m-1]+dfs(0,0,m-1,n,m,dp,dy,grid);
    }
};