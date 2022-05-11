class Solution {
public:
//     int count(int curPos , int &n , int vowel, vector<vector<int>> &dp)
//     {
//         if(curPos == n)
//             return 1;
        
//         if(dp[curPos][vowel] != -1)
//             return dp[curPos][vowel];
        
//         dp[curPos][vowel]=0;
        
//         for( int i = vowel ; i < 5 ; i++)
//         {
//             dp[curPos][vowel]+=count ( curPos+1 , n , i , dp);
//         }
        
//         return dp[curPos][vowel];
//     }
    int countVowelStrings(int n) {
        vector<vector<int>> dp (n+1, vector<int> (5,0));
        
        dp[0][0]=1;
        int ans=0;
        
        for( int i = 1; i <= n ; i++ )
        {
            for ( int j = 0 ; j < 5 ; j++)
            {
                dp[i][j]+=dp[i-1][j];
                
                if(j>0)
                    dp[i][j]+=dp[i][j-1];
                
                if(i==n)
                ans+=dp[n][j];
            }
        }
    
        return ans;
    }
};