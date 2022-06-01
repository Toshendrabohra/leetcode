// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    void dfs( vector<vector<int>>&matrix , int &n ,int &m, vector<vector<int>>&ans, int &flag , int x, int y)
    {
        if(x == n-1 && y == n-1)
        {
            flag=1;
            ans[x][y]=1;
            return ;
        }
        if(matrix[x][y]==0)
        return ;
        
        for( int i=1; i<=matrix[x][y]; i++)
        {
            if( y+i <n && matrix[x][y+i]!=0)    
            {
                dfs(matrix,n,m,ans,flag,x,y+i);
                if(flag==1)
                {
                    ans[x][y]=1;
                    return ;
                }
            }
            
            if( x+i <n && matrix[x+i][y]!=0)    
            {
                dfs(matrix,n,m,ans,flag,x+i,y);
                if(flag==1)
                {
                    ans[x][y]=1;
                    return ;
                }
            }
            
        }
        
    }
	vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
	   // Code here
	   int n = matrix.size();
	   int m = matrix[0].size();
	   
	   vector<vector<int>> ans( n, vector<int> (m,0));
	 
	   matrix[n-1][m-1]=1;
	   
	   int flag=0;
	    dfs(matrix, n, m, ans, flag, 0, 0);
	    
	    if(flag==0)
	    return {{-1}};
	    
	    return ans;
	    
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends