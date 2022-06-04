// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool chk( long n, long m, long l, long h[], long a[], long x)
    {
      long  long tot=0;
        for( long i = 0; i < n ; i++)
        {
          //long  long v=;
            if(h[i]+a[i]*x>=l)
            tot+=h[i]+a[i]*x;
            
            if(tot>=m)
            return true;
        }
        
        return tot>=m;
    }
    long buzzTime(long n, long m, long l, long h[], long a[])
    {
        // code here
        long left=1, right=m;
        
        // while(!chk(n, m, l, h, a, right))
        // right*=2;
        
        long ans = -1;
        int cnt=0;
        while(left <= right)
        {
            long mid = (right-left)/2+left;
            
            if(chk(n, m, l, h, a, mid))
            {
                right = mid - 1;
                ans=  mid;
            }
            else
            left= mid + 1;
            cnt++;
        }
        //cout<<cnt;
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long N, M, L;
        cin>>N>>M>>L;
        long H[N], A[N];
        for(long i = 0;i < N;i++) 
            cin>>H[i]>>A[i];
        
        Solution ob;
        cout<<ob.buzzTime(N, M, L, H, A)<<"\n";
    }
    return 0;
}  // } Driver Code Ends