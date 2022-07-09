// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    void allpaths(int n, int m, int x, int y, vector<vector<int>> &grid,vector<vector<int>> &ans,vector<int> path)
    {
        if(x == n - 1 && y == m - 1)
        {
            path.push_back(grid[x][y]);
            ans.push_back(path);
            return;
        }
        if(x == n || y == m)
        return;
        path.push_back(grid[x][y]);
        allpaths(n,m,x+1,y,grid,ans,path);
        allpaths(n,m,x,y+1,grid,ans,path);
        
    }
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        // code here
        vector<vector<int>> ans;
        vector<int> x;
         allpaths(n,m,0,0,grid,ans,x);
         return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends