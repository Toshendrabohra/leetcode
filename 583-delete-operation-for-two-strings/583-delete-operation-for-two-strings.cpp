class Solution {
public:
    int recur(int p1, int p2, string &s1, string &s2, vector<vector<int>> &dp , int &ans)
    {
        if(p1 >= s1.size() || p2 >= s2.size())
            return 0;
            
        if(dp[p1][p2] != -1)
            return dp[p1][p2];
        
        dp[p1][p2] = 0;
        if(s1[p1] == s2[p2])
          dp[p1][p2] = 1+ recur(p1+1,p2+1,s1,s2,dp,ans);
        
         dp[p1][p2] = max(dp[p1][p2] ,recur(p1+1,p2,s1,s2,dp, ans) );
         dp[p1][p2] = max(dp[p1][p2] ,recur(p1,p2+1,s1,s2,dp, ans) );
        
        ans = max(ans, dp[p1][p2]);
        return dp[p1][p2];
        
    }
    int minDistance(string word1, string word2) {
        
       vector<vector<int>> dp(word1.size()+1, vector<int> (word2.size() + 1, -1) );
         
        int ans = 0;
        
        recur(0, 0, word1, word2, dp, ans);
        return word1.size() + word2.size() - 2*ans;
    }
};