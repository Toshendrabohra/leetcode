// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    
   static bool comp(int a,int b)
    {
        
        int cnt1=0,cnt2=0;
        while(a)
        {
            
            cnt1+=a&1;
            a=a>>1;
        }
        while(b)
        {
            cnt2+=b&1;
            b=b>>1;
        }
       
        return cnt1>cnt2;
    }
    
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        stable_sort(arr,arr+n,comp);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends