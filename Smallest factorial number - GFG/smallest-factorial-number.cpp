// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        int count( int n)
        {
            int cnt = 0 ;
            
            while(n>1)
            {
                cnt += n/5;
                n/=5;
            }
            
            return cnt;
        }
        int findNum(int n)
        {
        //complete the function here
            int l = 1, r = n * 5;
            
            int ans = r;
            
            while( l <= r)
            {
                int mid = (l + r)/2;
                
                int cnt = count(mid);
                
                if(cnt >= n)
                {
                    ans = mid;
                    r = mid - 1;
                }
                else
                l = mid + 1;
            }
            
            return ans;
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends