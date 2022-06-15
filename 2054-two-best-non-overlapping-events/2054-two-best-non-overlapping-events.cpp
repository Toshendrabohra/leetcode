class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int k = 2;
         vector<int> cordinates;
        for( int i = 0; i < events.size(); i++)
        {
            cordinates.push_back(events[i][0]);
            cordinates.push_back(events[i][1]);
        }
        
        
        sort(cordinates.begin(), cordinates.end());
        sort(events.begin(), events.end());
         
        int n = cordinates.size();
        int dp[n+1][k+1];
        memset(dp, 0, sizeof(dp));
        int indx = 0;
        map<int,int> compressed;
        
        for( int i = 0; i < n; i++)
        {
            compressed[cordinates[i]] = i+1;
        }
        
        int ans = 0;
       
        for(int i = 1; i <= n ; i++ )
        {
               for(int j = 0; j <= k; j++)
            {
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
            }

             
            while(indx < events.size() && events[indx][0] == cordinates[i-1])
            {
                   int dash_co = compressed[events[indx][1]];
                for(int j = 0; j < k; j++)
                {
                    dp[dash_co][j+1] = max(dp[dash_co][j+1], dp[i][j] + events[indx][2]);
                }
                
                indx++;
            }
            
        }
        
        for( int i = 1; i <= k; i++)
            ans = max(ans, dp[n][i]);
        return ans;
    }
};