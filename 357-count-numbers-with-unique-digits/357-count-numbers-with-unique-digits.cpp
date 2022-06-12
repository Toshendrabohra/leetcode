class Solution
{
    public:
        int count(int n, int hash, vector < vector < int>> &dp, bool used)
        {
            if (n == 0)
            {
                if (used)
                    return 1;
                else
                    return 0;
            }

            if (dp[n][hash]!=-1)
                return dp[n][hash];
            
            dp[n][hash] = 0 ;
            
            if(!used)
            {
                dp[n][hash] += count(n-1, hash, dp, used);
            }
            
            for( int i = 0; i<10 ; i++)
            {
                if (hash&(1<<i))
                {
                    if(i == 0 && used)
                        dp[n][hash] += count(n-1, hash^1 , dp, used);
                    else if(i!=0)
                        dp[n][hash] += count(n-1, hash^(1<<i) , dp, true);
                }
                
            }
            
            return dp[n][hash];

        }

    int countNumbersWithUniqueDigits(int n)
    {

        int hash = (1 << 10) - 1;
        vector<vector < int>> dp(n + 1, vector<int> (hash + 1, -1));
        return count(n, hash, dp, false) + 1;
    }
};