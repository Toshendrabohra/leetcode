class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
     vector<int>    dp(amount+1,amount+100);
       dp[0]=0;
        for(int i=0;i<coins.size();i++)
        {
            for(int j=coins[i];j<=amount;j++)
            {
                dp[j]=min(dp[j],dp[j-coins[i]]+1);
            }
        }
        if(dp[amount]<amount+100)
        return dp[amount];
        else
            return -1;
        
    }
};