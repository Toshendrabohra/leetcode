class Solution {
public: 
    int countVowelPermutation(int n) {
        int mod = 1e9 + 7;
        unordered_map<char,int> hash;
        vector<char> a = {'a', 'e', 'i', 'o', 'u'};
        
        for(int i = 0; i < 5; i++)
            hash[a[i]] = i;
        
        unordered_map<char,vector<char>> adj;
        
        adj['a'] = {'e', 'i', 'u'};
        adj['e'] = {'a', 'i'};
        adj['i'] = {'e', 'o'};
        adj['o'] = {'i'};
        adj['u'] = {'i', 'o'};
        
        long long int dp[n+1][5];
        memset(dp, 0, sizeof(dp));
        
        for(int i = 0; i < 5; i++)
        {
            dp[0][i] = 1;
        }
        
        for ( int i = 0; i < n - 1; i++)
        {
            for( int j = 0; j < 5; j++)
            {
                for(auto k:adj[a[j]])
                dp[i+1][j] = (dp[i+1][j] + dp[i][hash[k]])%mod;
            }
        }
        
        int final_ans = 0;
        for(int i = 0 ; i < 5; i++)
        {
            final_ans = (final_ans+dp[n-1][i])%mod;
        }
        
        return final_ans;
    }
};