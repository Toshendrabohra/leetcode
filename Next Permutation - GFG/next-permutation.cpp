// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> arr){
        // code here
        int x=n-1;
        int pivot=n-2;
        while(pivot>0)
        {
        while(x>pivot && arr[x]<=arr[pivot])
        {
            x--;
        }
        if(x==pivot)
        {
            pivot--;
            x=n-1;
            
        }
        else
        {
            break;
        }
        }
        if(pivot!=-1)
        swap(arr[x],arr[pivot]);
        
        sort(arr.begin()+pivot+1,arr.end());
        return arr;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends