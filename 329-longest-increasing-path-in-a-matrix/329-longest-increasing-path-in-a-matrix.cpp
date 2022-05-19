class Solution {
public:
    int length(int x,int y,vector<vector<int>>& mat,vector<vector<int>>& dp,int &ans){
        int n = mat.size();
        int m = mat[0].size();
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        
        int count = 1;

        for(int i = 0;i<4;i++){
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            if(x1 >= 0 and x1 < n and y1 >= 0 and y1 < m and mat[x1][y1] > mat[x][y]){
                if(dp[x1][y1] == 0) count = max(count,length(x1,y1,mat,dp,ans) + 1);
                else count = max(count,dp[x1][y1] + 1);
            }
        }

        ans = max(ans,count);
        return dp[x][y] = count;
    }
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        vector<vector<int>> dp(n,vector<int>(m,0));

        for(int r = 0;r<n;r++){
            for(int c = 0;c<m;c++){
                if(dp[r][c] == 0) length(r,c,mat,dp,ans);
            }
        }

        return ans;
    }
};