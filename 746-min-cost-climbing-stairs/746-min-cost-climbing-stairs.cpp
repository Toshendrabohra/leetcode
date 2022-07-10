class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
       vector<int> dp(cost.size(), 0);
        
        for( int i = 0; i < cost.size(); i++)
        {
            if(i <= 1)
                dp[i] = cost[i];
            else
            {
                dp[i] = min(dp[i-1],dp[i-2]) + cost[i];
            }
        }
        int n = cost.size();
        return min(dp[n-1],dp[n-2]);
    }
};