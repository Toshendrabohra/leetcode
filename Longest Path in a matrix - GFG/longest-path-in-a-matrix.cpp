// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
int ROW,COL;
 int dfs(int i,int j,vector<vector<int>>& m,vector<vector<int>>& dp){
        vector<pair<int,int>>dr={{-1,0},{0,-1},{0,1},{1,0}};
        if(dp[i][j])return dp[i][j];
        int count=1;
        for(auto r:dr){
            int x=i+r.first, y=j+r.second;
            if(x<0||x>ROW-1||y<0||y>COL-1)continue;
            if(m[i][j]<m[x][y])
                count=max(count,dfs(x,y,m,dp)+1);
        }
        dp[i][j]=count;
        return count;
 }
    int longestIncreasingPath(vector<vector<int>>& m) {
        // Code here
        ROW=m.size(),COL=m[0].size();
        vector<vector<int>>dp(ROW,vector<int>(COL));
        int ans=0;
        for(int i=0;i<ROW;i++){
            for(int j=0;j<COL;j++){
                ans=max(dfs(i,j,m,dp),ans);
            }
        }
        return ans;
    }
    
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)cin >> matrix[i][j];
		Solution obj;
		int ans = obj.longestIncreasingPath(matrix);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends