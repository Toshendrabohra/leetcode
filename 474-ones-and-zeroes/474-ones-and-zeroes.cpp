class Solution
{
    public:
        int findMaxForm(vector<string> &strs, int m, int n)
        {

            int dp[m + 1][n + 1];
            memset(dp, 0, sizeof(dp));
            int sz = strs.size();

            int ans = 0;
            for (int i = 0; i < sz; i++)
            {
                int cnt = 0;
                int tot = strs[i].size();

                for (int j = 0; j < tot; j++)
                {
                    if (strs[i][j] == '0')
                        cnt++;
                }
                for (int j = m; j >= cnt; j--)
                {
                    for (int k = n; k >= tot - cnt; k--)
                    {
                        dp[j][k] = max(dp[j][k], 1 + dp[j - cnt][k - (tot - cnt)]);
                        ans = max(ans, dp[j][k]);
                    }
                }
            }
            
            return ans;
        }
};