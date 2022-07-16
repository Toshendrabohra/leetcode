class Solution {
public:
    int mod  = 1e9+7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int dp[2][m][n];
        memset(dp,0, sizeof(dp));
        int dpx[] = {1,0,-1,0};
        int dpy[] = {0,1,0,-1};
        for(int move = 1; move <= maxMove; move++)
        {
            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    dp[move%2][i][j] = 0;
                    for(int k = 0; k < 4; k++)
                    {
                        int x = dpx[k] + i;
                        int y = dpy[k] + j;
                        if(x<0 || y<0 || x>=m || y>=n)
                        {
                            dp[move%2][i][j] += 1;
                        }
                        else
                        {
                            dp[move%2][i][j] = ((long long int)dp[move%2][i][j] + (long long int)dp[(move+1)%2][x][y])%mod;
                        }
                    }
                }
            }
        }
        
        return dp[maxMove%2][startRow][startColumn];
    }
};