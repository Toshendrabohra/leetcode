class Solution {
public:
    
    int calc(int n, vector<int> &dp)
    {
        if(dp[n] != -1)
            return dp[n];
        
        return calc(n-1, dp) + calc(n-2, dp);
    }
    
    int fib(int n) {
        vector<int> dp(30+1,-1);
        dp[0] = 0;
        dp[1] = 1;
        return calc(n,dp);
    }
};