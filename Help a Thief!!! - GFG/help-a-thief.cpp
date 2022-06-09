// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxCoins(int A[], int B[], int T, int N) {
        // code here
        vector<pair<int, int>> p;
        
        for( int i = 0; i < N; i++)
        {
            p.push_back({B[i], i});
        }
        
       sort(p.begin(), p.end());
        
        int ans = 0, tot_plates = 0;
        
        for( int i = N - 1; i >= 0 ; i--)
        {
          int  cur_plates = min (T - tot_plates, A[p[i].second]);
            ans += B[p[i].second] * cur_plates;
            tot_plates += cur_plates;
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int T,N;
        cin>>T>>N;
        
        int A[N], B[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<N; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.maxCoins(A,B,T,N) << endl;
    }
    return 0;
}  // } Driver Code Ends