// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    bool vis[501][501];
   
   Solution(){
       memset(vis,false,sizeof(vis));
   }
   
   bool isValid(int x,int y,int n,int m,vector<vector<char>> &grid){
       if(x < 0 || x >= n || y < 0 || y >= m) return (false);
       if(vis[x][y] || grid[x][y] == '0') return (false);
       return (true);
   }
   
   void dfs(int x,int y,int n,int m,vector<vector<char>> &grid){
       vis[x][y] = true;
       int dx[] = {-1,-1,0,1,1,1,0,-1};
       int dy[] = {0,1,1,1,0,-1,-1,-1};
       
       for(int i = 0; i < 8; i++){
           int nx = x + dx[i];
           int ny = y + dy[i];
           if(isValid(nx,ny,n,m,grid)){
               dfs(nx,ny,n,m,grid);
           }
       }
   }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
         int n = grid.size();
       int m = grid[0].size();
       
       int cnt = 0;
       for(int i = 0; i < n; i++){
           for(int j = 0; j < m; j++){
               if(grid[i][j] == '1' && !vis[i][j]){
                   cnt++;
                   dfs(i,j,n,m,grid);
               }
           }
       }
       
       return (cnt);
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends