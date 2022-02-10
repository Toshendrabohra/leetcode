// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int xorCal(int k){
        // code here
        int flag=0;
        int ans=0;
        if(k==1)
        return 2;
        for(int i=10;i>=0;i--)
        {
            if(k&(1<<i))
            {
                if(!flag)
                flag=1;
                else
                ans+=(1<<i);
               
            }
            else if(flag)
            {
                return -1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        
        Solution ob;
        cout<<ob.xorCal(k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends