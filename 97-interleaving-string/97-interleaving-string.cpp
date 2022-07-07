class Solution {
public:
    int check(string &s1, string &s2, string &s3,int x1, int x2, int pos, vector<vector<int>> &dp)
    {
        if(x1 >= s1.size() && x2 >= s2.size() && pos == s3.size())
            return 1;
        if(x2 > s2.size() || x1 > s1.size())
            return 0;
     
        if(dp[x1][x2] != -1)
            return dp[x1][x2];
        int x = 0;
        if(s1[x1] == s3[pos])
        {
            x = check(s1, s2, s3, x1+1, x2, pos+1, dp);
        }
        if(s2[x2] == s3[pos])
        {
            x+= check(s1,s2,s3,x1, x2+1, pos+1, dp);
        }
        dp[x1][x2] = x;
        return dp[x1][x2] >= 1;
        
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
    
       return check(s1,s2,s3,0,0,0,dp) >= 1 ;
        
        // for( int i = 0; i < s1.size(); i++)
        // {
        //     for( int j = 0; j < s2.size(); j++)
        //         cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
      //  return dp[0][0] >= 1;
    }
};