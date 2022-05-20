// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    vector<int> farNumber(int n,vector<int> arr){
        //code here
        vector<pair<int,int>> p;
        int prev=INT_MAX;
        
        for(int i=n-1 ; i>=0 ; i--)
        {
            if(arr[i]< prev)
            {
                p.push_back({arr[i],i});
                prev=arr[i];
            }
        }
        sort(p.begin(),p.end());
        
        vector<int> ans;
        
        for(int i=0; i<n ; i++)
        {
            pair<int,int> dum={arr[i],-1};
            int indx=lower_bound(p.begin(), p.end(), dum)-p.begin();
            
            if(indx>0 && p[indx-1].second>i)
            ans.push_back(p[indx-1].second);
            else
            ans.push_back(-1);
        }
        
        return ans;
    }
};

// { Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++)
            cin>>Arr[i];
        Solution obj;
        vector<int> answer=obj.farNumber(N,Arr);
        for(auto i:answer)
            cout<<i<<" ";
        cout<<endl;
  }
}  // } Driver Code Ends