// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int count(int prev, string &s, int pos, vector<vector<int>> &dp)
	{
	    if( pos == s.size())
	    return 1;
	    
	    if(dp[pos][prev] != -1)
	    return dp[pos][prev];
	    
	    dp[pos][prev] = 0;
	    
	    int sum = 0;
	    
	    for( int i = pos; i< s.size(); i++)
	    {
	        sum += s[i] - '0';
	        
	        if(sum >= prev)
	        {
	            dp[pos][prev] += count (sum, s, i+1, dp);
	        }
	    }
	    
	    return dp[pos][prev];
	}
	int TotalCount(string str){
	    // Code here
	     vector<vector<int>> dp(101, vector<int> (101*9,-1));
	     
	    return count(0, str, 0, dp);
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends