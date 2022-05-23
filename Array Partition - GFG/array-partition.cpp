// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool partitionArray(int n, int k, int m, vector<int> &a){
        // code here
        sort(a.begin(), a.end());
        vector<bool> dp(n+1,false);
        vector<int> indx(n+1,-1);
        dp[0]=true;
        indx[0]=-1;
        for(int i=0;i<n;i++)
        {
            //cout<<a[i]<<" ";
            if(dp[i]==true)
            {
                //cout<<i;
                if(k+i-1<n && a[k+i-1]-a[i]<=m)
                    dp[k+i]=true,indx[k+i]=i;
                
                if(i<n && indx[i]!=-1 && a[i]-a[indx[i]] <=m)
                {
                    dp[i+1]=true;
                    
                    if(indx[i+1]==-1)    
                    indx[i+1]=indx[i];
                
                }
            }
            //cout<<dp[i]<<" "<<endl;
        }
        //cout<<dp[n];
        // cout<<endl;
        // for(int i=0;i<n;i++)cout<<dp[i]<<" "<<indx[i]<<endl;
        return dp[n];
        
    }
};

// { Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, K, M;
        cin >> N >> K >> M;
        vector<int> A(N);
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }
        Solution obj;
        bool ans = obj.partitionArray(N, K, M, A);
        if(ans){
            cout << "YES\n";
        }
        else{
            cout<< "NO\n";
        }
    }
}
  // } Driver Code Ends