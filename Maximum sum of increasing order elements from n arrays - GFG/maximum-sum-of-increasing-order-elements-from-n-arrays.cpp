// { Driver Code Starts
// CPP program to find maximum sum
// by selecting a element from n arrays
#include<bits/stdc++.h>

using namespace std;

// To calculate maximum sum by
// selecting element from each array
int maximumSum( int n,int m, vector<vector<int>> &a);



// Driver program to test maximumSum
int main() {
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector<vector<int>> arr(n, vector<int>(m,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            cin>>arr[i][j];
            
        cout << maximumSum(n,m,arr)<<endl;
    
    }
    return 0;

}
// } Driver Code Ends


int maximumSum( int n,int m, vector<vector<int>> &a) {
int ans[n][m];
for(int i=0;i<n;i++)
{
    sort(a[i].begin(),a[i].end());
    for(int j=0;j<m;j++)
    {
        int x=-1;
        if(i>0)
        {
            x=lower_bound(a[i-1].begin(),a[i-1].end(),a[i][j])-a[i-1].begin();
            x--;
        if(x==-1 || ans[i-1][x]==-1)
        {
        ans[i][j]=-1;
        }
        else
        ans[i][j]=a[i][j]+ans[i-1][x];
        }
        else
        {
            ans[i][j]=a[i][j];
        
        }
        
        if(j>0)
        ans[i][j]=max(ans[i][j],ans[i][j-1]);
       // cout<<ans[i][j]<<" ";
    }
    //cout<<endl;
   
}
     if(ans[n-1][m-1]==-1)
     return 0;
     
     return ans[n-1][m-1];
    // Complete the function
}