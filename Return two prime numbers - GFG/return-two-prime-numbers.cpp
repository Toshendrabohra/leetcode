// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
 static bool isPrime(int n)
    {
        for(int i = 2; i <= sqrt(n); i++)
            if(n%i==0)
                return false;
        return true;        
    }
    vector<int> primeDivision(int N){
        // code here
        
        for(int i = 2; i <= N/2; i++)
            if(isPrime(i)&&isPrime(N-i))
                return {i, N-i};
        return {};     
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.primeDivision(N);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}  // } Driver Code Ends