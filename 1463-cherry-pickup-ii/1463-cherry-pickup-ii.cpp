class Solution {
public:
    bool valid(int x,int y,int &n,int &m)
    {
        if(x>=0 && x<n && y<m && y>=0)
            return true;
        return false;
    }
    int dfs(int r1x,int r1y,int r2x,int r2y,int &n,int &m,vector<vector<vector<vector<int>>>> &dp,vector<int> &dy,vector<vector<int>>& grid)
    {
       // cout<<r1x<<" "<<r1y<<" "<<r2x<<" "<<r2y<<endl;
        if(dp[r1x][r1y][r2x][r2y]!=-1)
            return dp[r1x][r1y][r2x][r2y];
        int mx=0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(valid(r1x+1,r1y+dy[i],n,m) && valid(r2x+1,r2y+dy[j],n,m))
                {
                    mx=max(mx,grid[r1x+1][r1y+dy[i]]+((r1x==r2x && r1y+dy[i]==r2y+dy[j])?0:grid[r2x+1][r2y+dy[j]]+dfs(r1x+1,r1y+dy[i],r2x+1,r2y+dy[j],n,m,dp,dy,grid)));
                }
            }
        }
         return dp[r1x][r1y][r2x][r2y]=mx;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<vector<int>>>> dp(n,vector<vector<vector<int>>>
                                              (m,vector<vector<int>>
                                              (n,vector<int>(m,-1))));
        vector<int > dy={-1,0,1};
       return grid[0][0]+grid[0][m-1]+dfs(0,0,0,m-1,n,m,dp,dy,grid);
    }
};