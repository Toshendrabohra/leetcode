// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    vector<int> TopK(vector<int>& array, int k)
    {
    vector<int> cust_id(10001,0);
    int size_arr=array.size();
    for(int i=0;i<size_arr;i++)
    {
        cust_id[array[i]]++;
    }
    priority_queue<pair<int,int>> most_k_freq;
    vector<int> ans;
    for(int i=0;i<10001;i++)
    {
        if(cust_id[i]>0)
        {
            most_k_freq.push({cust_id[i],i});
        }
    }
     k=min(k,(int)most_k_freq.size());
    for(int i=0;i<k;i++)
    {
        ans.push_back(most_k_freq.top().second);
        most_k_freq.pop();
    }
    return ans;
    
        // code here
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k ;
        cin>>n;
        
        vector<int>array(n);
        
        for(int i=0; i<n; i++)
            cin>>array[i];
            
        cin>>k;
        
        Solution obj;
        vector<int> result = obj.TopK(array,k);
        
        for(int i=0; i<result.size();i++)
            cout<<result[i]<<" ";

        cout<<"\n";

    }
    return 0;
}  // } Driver Code Ends