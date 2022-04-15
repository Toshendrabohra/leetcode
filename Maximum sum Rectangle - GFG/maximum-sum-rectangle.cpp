// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maximumSumRectangle(int r, int c, vector<vector<int>> m) {
        // code here
        vector<vector<int>> mat(r+1,vector<int>(c+1,0));
        
        for(int i=r-1;i>=0;i--) 
        {
            for(int j=0;j<c;j++)
            {
                mat[i][j]+=mat[i+1][j]+m[i][j];
            }
        }
        
        for(int i=0;i<r;i++)
        {
         for(int j=0;j<c;j++)
               {
                   if(j>0)
                   mat[i][j]+=mat[i][j-1];
               }
        }
               
        int ans=INT_MIN;
        for(int i=0;i<r;i++)
        {
               for(int j=i;j>=0;j--)
               {
               int mn=0;
                   for(int k=0;k<c;k++)
                   {
                   ans=max(ans,mat[j][k]-mat[i+1][k]-mn);
                   mn=min(mn,mat[j][k]-mat[i+1][k]);
                   }
               }
        }
        return ans;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  // } Driver Code Ends