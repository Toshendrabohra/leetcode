// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    void prank(long long a[], int n){
        // code here
        for(int i=0;i<n;i++)
        {
            a[i]++;
        }
        for(int i=0;i<n;i++)
        {
            if(a[i]<0)
            continue;
            int x=i;
            int ord=a[i];
           // cout<<a[i]<<endl;
            while(a[x]!=i+1)
            {
                int next=a[x]-1;
                a[x]=-a[next];
                x=next;
            }
            a[x]=-(ord);
            
        }
        for(int i=0;i<n;i++)
        {
            a[i]*=-1;
            a[i]--;
        }
        
        
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long a[n];
        for(int i = 0 ;i<n;i++){
            cin>>a[i];
        }
        Solution ob;
        ob.prank(a,n);

        for(int i = 0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<"\n";
    }
}

  // } Driver Code Ends