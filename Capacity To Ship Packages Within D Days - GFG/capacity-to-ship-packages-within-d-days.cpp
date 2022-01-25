// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool chk(int *&arr,int mid,int n,int d)
    {
        int cnt=0;
        int cur=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>mid)
            return false;
            else if(cur+arr[i]<=mid)
            {
                cur+=arr[i];
            }
            else
            {
                cur=arr[i];
                cnt++;
            }
        }
        if(cur)
        cnt++;
        return (cnt<=d);
        
    }
    int leastWeightCapacity(int arr[], int n, int d) {
        // code here
        int l=0,r=1e9;
        int ans=r;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(chk(arr,mid,n,d))
            {
                ans=min(ans,mid);
                r=mid-1;
            }
            else
            l=mid+1;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}  // } Driver Code Ends