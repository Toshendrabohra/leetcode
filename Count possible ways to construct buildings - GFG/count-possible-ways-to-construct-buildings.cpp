// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int mod = 1e9 + 7;
	
	long long int power(long long int base, long long int ex)
	{
	    if(ex == 0)
	    return 1;
	    
	    if(ex == 1)
	    return base;
	    
	    long long z = power(base, ex/2);
	    
	    return (z*z*power(base,ex%2))%mod;
	}
	
	int TotalWays(int n)
	{
	  vector<vector<int>> dp(n+1, vector<int> (2, 0));
	  dp[0][1] = 1;
	  for(int i = 0; i < n; i++)
	  {
	      dp[i+1][0] = dp[i][1];
	      dp[i+1][1] = (dp[i][1] + dp[i][0])%mod;
	  }
	  dp[n][0] = (dp[n][0] + dp[n][1])%mod;
	  
	    return ((long long int)dp[n][0]*dp[n][0])%mod;
	    // Code here
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends