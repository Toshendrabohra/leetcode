// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    static bool comp( vector<int> &a, vector<int> &b)
    {
        if(a[1]==0 || b[1]==0)
        return false;
        double x= (1.0*a[0])/a[1];
        double y= (1.0*b[0])/b[1];
        
        if( x<=y)
        return true;
        return false;
    }
    vector<int> numAndDen(int n, int d) {
        // code here
        vector<vector<int>> ans;
        double x=-1;
        int nx,ny;
        for( int i=1;i<=10000;i++)
        {
            vector<int> dum(2);
            dum[1]=i;
            dum[0]=(i*n)/d;
            
            if((i*n)%d == 0)
            {
                dum[0]--;
            }
            
            double dval=(1.0*dum[0])/dum[1];
            if(x < dval)
            {
                x=dval;
                nx=dum[0];
                ny=dum[1];
            }
            //ans.push_back(dum);
        }
        
        // sort(ans.begin(), ans.end(), comp);
        // return {1,1};
        return {nx,ny};
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,d;
        cin >> n >> d;
        Solution ob;
        vector<int>ans=ob.numAndDen(n,d);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends