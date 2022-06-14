class Solution
{
    public:
        long long maxTaxiEarnings(int n, vector<vector < int>> &rides)
        {
            vector<long long> dp(n + 1, 0);
            sort (rides.begin(), rides.end());
            int indx = 0;
            for(int i = 1; i <= n; i++)
            {
                dp[i] = max(dp[i], dp[i-1]);
                
                while(indx < rides.size() && rides[indx][0] == i)
                {
                    dp[rides[indx][1]] = max( dp[rides[indx][1]], dp[i] + rides[indx][1] - rides[indx][0] + rides[indx][2]);
                    indx++;
                }
            }
            
            return dp[n];
            
        }
};