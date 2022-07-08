class Solution
{
    public:
        int dp[101][101][21];

    int memo(vector<int> &houses, vector<vector< int>> &cost, int m, int n, int target, int pos, int cnt, int prev)
    {
        if (pos == m && cnt == target)
            return 0;
        if (pos == m)
            return 1e7;
        if(cnt > target)
            return 1e7;
        
        if (dp[pos][cnt][prev] != -1)
            return dp[pos][cnt][prev];

        dp[pos][cnt][prev] = INT_MAX;

        if (houses[pos] != 0)
            return dp[pos][cnt][prev] = memo(houses, cost, m, n, target, pos + 1, cnt + ((prev == houses[pos]) ? 0 : 1), houses[pos]) ;

        for (int i = 1; i <= n; i++)
        {
            dp[pos][cnt][prev] = min(dp[pos][cnt][prev],
                memo(houses, cost, m, n, target, pos + 1, cnt + ((prev == i) ? 0 : 1), i) + cost[pos][i - 1]
           );
        }

        return dp[pos][cnt][prev];
    }

    int minCost(vector<int> &houses, vector<vector< int>> &cost, int m, int n, int target)
    {

        memset(dp, -1, sizeof(dp));
        int x = memo(houses, cost, m, n, target, 0, 0, 0);
        if (x >= 1e7)
            return -1;
        return x;
    }
};