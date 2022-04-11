// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
 

	public:
	bool val(int n,int m,int x,int y)
	{
	    if(x>=0 && x<n && y>=0 && y<m)
	    return true;
	    return false;
	}
	int numberOfCells(int n, int m, int r, int c, int u, int d, vector<vector<char>> &mat)
	{
		// Your code goes here
		vector<vector<int>> vis(n,vector<int> (m,0));
		queue<vector<int>> q;
		
		int cnt=0;
		if(mat[r][c]=='.')
		q.push({r,c,u,d}),cnt++,vis[r][c]=1;
		
		int dx[]={0,0,-1,1};
		int dy[]={1,-1,0,0};
		while(!q.empty())
		{
		    
		    vector<int> cur=q.front();
		    q.pop();
		    for(int i=0;i<4;i++)
		    {
		        int x=cur[0]+dx[i];
		        int y=cur[1]+dy[i];
		        int up=cur[2];
		        int down=cur[3];
		        if(i==2)
		        up--;
		        else if(i==3)
		        down--;
		        if(val(n,m,x,y) && mat[x][y]=='.' && vis[x][y]==0 && up>=0 && down>=0)
		        {
		            cnt++;
		            vis[x][y]=1;
		            q.push({x,y,up,down});
		        }
		    }
		}
		return cnt;
	}

};

// { Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;

    while (t--)
    {
    	int n, m, r, c, u, d;
        cin >> n >> m >> r >> c >> u >> d;
        
        vector<vector<char>> mat(n, vector<char>(m, '.'));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < m; j++)
        	{
        		cin >> mat[i][j];
        	}
        }

      

        Solution obj;
        cout << obj.numberOfCells(n, m, r, c, u, d, mat) << "\n";
    
    }

    return 0;
}


  // } Driver Code Ends