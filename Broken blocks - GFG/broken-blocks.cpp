// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
int MaxGold(vector<vector<int>>&matrix){
    // Code here
    int m=matrix.size();
    int n=matrix[0].size();
    int ans=0;
    
    for(int i=0 ; i< m ; i++)
    {
        for( int j=0;j<n ; j++)
        {
            if(matrix[i][j]==-1)
            {
               // cout<<"-1 ";
            continue;
            }            
            int cur=-1;
            if(i-1>=0 && j-1>=0 && matrix[i-1][j-1]!=-1)
            cur=max(cur, matrix[i][j]+matrix[i-1][j-1]);
            
            if(i-1>=0 && j>=0 && matrix[i-1][j]!=-1)
            cur=max(cur, matrix[i][j]+matrix[i-1][j]);
            
            if(i-1>=0 && j+1<n && matrix[i-1][j+1]!=-1)
            cur=max(cur, matrix[i][j]+matrix[i-1][j+1]);
            
            if(i!=0)
            matrix[i][j]=cur;
            
            ans=max(ans, matrix[i][j]); 
            //cout<<matrix[i][j]<<" ";
        }
        //cout<<endl;
    }
    
    return ans;
}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>matrix(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		int ans = obj.MaxGold(matrix);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends