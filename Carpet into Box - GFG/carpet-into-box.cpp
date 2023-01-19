//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int accomadate(int a, int b, int c, int d)
    {
        if(a <= c && b <= d)
            return 0;
        else if(a > c)
            return 1 + accomadate(a/2, b, c, d);
        else
            return 1 + accomadate(a, b/2, c, d);
    }
    int carpetBox(int A, int B, int C, int D){
        //code here
        return min(accomadate(A,B,C,D), accomadate(B,A,C,D));
    }
    
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends