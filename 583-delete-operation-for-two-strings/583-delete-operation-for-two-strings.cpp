class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int dp[word1.size()+1][word2.size()+1];
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        int tot = word1.size() + word2.size();
        
        for( int i = 0; i<word1.size(); i++)
        {
            for( int j = 0; j<word2.size(); j++)
            {
                dp[i+1][j+1] = max(dp[i][j], dp[i+1][j+1]);
                dp[i+1][j] = max(dp[i][j], dp[i+1][j]);
                dp[i][j+1] = max(dp[i][j], dp[i][j+1]);
                
                
                if(word1[i] == word2[j])
                {
                    dp[i+1][j+1]= max(dp[i][j]+1, dp[i+1][j+1]);
                }
                
                ans = max(ans, dp[i+1][j+1]);
            }
        }
        
        return tot - 2*ans;
    
    }
};