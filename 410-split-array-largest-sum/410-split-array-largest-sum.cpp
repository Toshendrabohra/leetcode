class Solution {
public:
    struct node
    {
      int sum;
      int max;
    };
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size();
        node dp[2][51][n+1];
        int ans=0;
            for(int j=0;j<=m;j++)
            {
                for(int k=0;k<=n;k++)
                {
                    dp[0][j][k].sum=-1;
                    dp[0][j][k].max=-1;
                    dp[1][j][k].sum=-1;
                    dp[1][j][k].max=-1;
                }
            }
         
        dp[0][0][0].sum=0;
        dp[0][0][0].max=0;
        for(int i=0;i<n;i++)
        {
            ans+=nums[i];
            //cout<<i<<endl;
            for(int j=0;j<m;j++)
            {
                for(int k=0;k<n;k++)
                {
                     //cout<<dp[i%2][j][k].sum<<" "<<dp[i%2][j][k].max<<" | ";
                   if(dp[i%2][j][k].sum!=-1)
                   {
                       //cout<<i<<" "<<j<<" "<<k<<" "<<
                          
                       dp[(i+1)%2][j][k+1].sum=dp[i%2][j][k].sum+nums[i];
                       dp[(i+1)%2][j][k+1].max=dp[i%2][j][k].max;
                       //new
                       dp[(i+1)%2][j+1][0].sum=0;
                if(dp[(i+1)%2][j+1][0].max==-1)
                dp[(i+1)%2][j+1][0].max=max(dp[i%2][j][k].max,dp[i%2][j][k].sum+nums[i]);
         else
 dp[(i+1)%2][j+1][0].max=min(dp[(i+1)%2][j+1][0].max,max(dp[i%2][j][k].max,dp[i%2][j][k].sum+nums[i]));    
                   }
                     dp[i%2][j][k].sum=-1;
                     dp[i%2][j][k].max=-1;
                }
                //cout<<endl;
            }
           // cout<<endl;
        }
        
      for(int i=0;i<n;i++)
      {
          if(dp[n%2][m-1][i].sum!=-1)
          ans=min(ans,max(dp[n%2][m-1][i].sum,dp[n%2][m-1][i].max));
          //cout<<max(dp[n%2][m-1][i].sum,dp[n%2][m-1][i].max)<<" ";
      }
        return ans;
        
    }
};