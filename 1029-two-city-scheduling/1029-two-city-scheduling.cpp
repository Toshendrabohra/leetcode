class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size()/2;
        int dp[2*n+1][n+1];
        
        for(int i=0;i<=2*n;i++)
        {
            for(int j=0;j<=n;j++)
                dp[i][j]=INT_MAX;
        }
        dp[0][0]=0;
        //dp[0][1]=0;
        for(int i=0;i<2*n;i++)
        {
            for(int j=0;j<=min(n,i+1);j++)
            {
                if(j==0)
                {
                    dp[i+1][j]=costs[i][1]+dp[i][j];
                }
                else
                {
                    if(dp[i][j]!=INT_MAX)
                    dp[i+1][j]=min(dp[i+1][j],dp[i][j]+costs[i][1]);
                    dp[i+1][j]=min(dp[i+1][j],dp[i][j-1]+costs[i][0]);
                }
               //cout<<dp[i+1][j]<<" ";
            }
          // cout<<endl;
        }
        return dp[2*n][n];
    }
};