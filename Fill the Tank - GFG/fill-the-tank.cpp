// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {

public:
    long long  dfs(int cur, int par, vector<long long > &dp, vector<vector<int>> &graph, int *cap, int &flag)
    {
       long long  mx = 0;
        long long cnt = 0;
       
            for(auto &i:graph[cur])
            {
                if(i!=par)
                {
                    dfs(i, cur, dp, graph, cap, flag);
                    mx = max(mx, dp[i]);
                    cnt++;
                }
            }
            
            dp[cur] = mx*cnt + cap[cur - 1];
            if(dp[cur] > 1e18)
            flag = 0;
    }
    
    long long minimum_amount(vector<vector<int>> &Edges, int num, int start, int *cap){
       // Code here
       vector<vector<int>> graph(num+1);
       vector<long long > dp(num+1,0);
      
       for( int i = 0; i < num -1 ; i++)
       {
           graph[Edges[i][0]].push_back(Edges[i][1]);
           graph[Edges[i][1]].push_back(Edges[i][0]);
       }
        
        int flag = 1;
        dfs(start, -1, dp, graph, cap, flag);
       
       if(flag == 0)
       return -1;
        return dp[start];
    }
};

// { Driver Code Starts.


int main()
 {
	int T;
	cin>> T;
	while (T--)
	{
	    int num, start;
	    cin>>num>>start;
	    int cap[num];
	    for(int i = 0; i<num; i++)
	        cin>>cap[i];
	    
	    vector<vector<int>> Edges(num);
	    for(int i=1;i < num;i++){
	        int u, v; cin >> u >> v;
	        Edges[i-1].push_back(u);
	        Edges[i-1].push_back(v);
	    }
	    
	    
    	Solution obj;
	    long long ans = obj.minimum_amount(Edges, num, start, cap);
	    cout << ans << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends