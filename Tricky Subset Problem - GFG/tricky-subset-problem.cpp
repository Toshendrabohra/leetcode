// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isPossible(long long s, long long N, long long X, long long A[])
    {
        // code here 
        vector<long long > x;
        
    long long  cur=s;
        x.push_back(cur);
        
        for( long long i = 0;  i < N ; i++)
        {
           long long  next=cur+A[i];
            x.push_back(next);
            if(next>=X)
            break;
            cur+=next;
          //  cout<<next<<" ";
        }
        
        for( long long  i = x.size()-1 ; i>=0 ; i--)
        {
            if(x[i]<=X)
            {
                X-=x[i];
            }
        }
        
        if(X)
        return 0;
        else
        return 1;
        
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long S, N, X;
        cin>>S>>N>>X;
        long long A[N];
        for(long long i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        if(ob.isPossible(S, N, X, A))
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}  // } Driver Code Ends