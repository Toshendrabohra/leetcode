//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:



int dp[12][1<<11];

int build(int cur, int n, int subset, vector<vector<int>> &cost)
{
    if(subset == 0)
    return 0;
    
    if(dp[cur][subset]!= -1)
        return dp[cur][subset];
    
    
    int mxcost =INT_MAX;
    int flag = 1;
    for(int i = 1; i < n; i++)
    {
        if(subset&(1<<i))
        {
            flag = 0;
            mxcost = min(mxcost, cost[cur][i] + build(i, n, subset^(1<<i), cost));
        }
    }
    
    if(flag)
    {
        if(subset&1)
        {
            mxcost = min(mxcost, cost[cur][0] + build(0, n, subset^(1<<0), cost));
        }
    }
    return dp[cur][subset] = mxcost;
}
int total_cost(vector<vector<int>>cost){
    // Code here
    memset(dp, -1, sizeof(dp));
    int n = cost.size();
    int subset = (1<<n) - 1;
    //dp[0][subset] = 0;
    
    return build(0, n, subset, cost);
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends