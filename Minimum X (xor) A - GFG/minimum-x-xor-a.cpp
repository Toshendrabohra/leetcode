// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        int cnt = __builtin_popcount(b);
        int x = 0;
        
        for( int i = 31; i >=0; i--)
        {
            if(a&(1ll<<i) && cnt)
            {
                x+=(1ll<<i);
                cnt--;
            }
        }
      //  cout<<cnt;
        for(int i = 0; i < 32;i++)
        {
            if(cnt && (x&(1ll<<i)) == 0)
            {
                x ^=(1ll<<i);
                // if(x&(1ll<<i) == 0)
                // cnt++;
                cnt--;
         //   cout<<x<<" ";    
            }
            
        }
        
        return x;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends