// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        // Your code goes here
        sort(arr,arr+n);
        long long int x = 0;
        long long int carry = 0;
        long long int dum = 1;
        for(int i = 0; i < n/2; i++)
        {
            long long int mul = arr[n-2*i-1] + arr[n - 2*i -2];
            x = dum*((mul+carry)%10) + x;
            carry = (mul+carry)/10;
            dum *= 10;
        }
        
        if(n%2)
        carry += arr[0];
        
        x = dum*(carry)+x;
        return x;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends