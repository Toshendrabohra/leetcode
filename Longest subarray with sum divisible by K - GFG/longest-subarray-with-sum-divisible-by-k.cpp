// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	   vector<int> mods(k+1,-1);
	   int cnt=0;
	   int ans=0;
	   
	   mods[0]=0;
	   for(int i = 0; i<n ; i++ )
	   {
	       cnt+=arr[i];
	       
	       if(mods[(cnt%k+k)%k]==-1)
	       mods[(cnt%k+k)%k]=i+1;
	       else
	       {
	           ans=max(ans, i+1-mods[(cnt%k+k)%k]);
	       }
	   }
	   
	   return ans;
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
  // } Driver Code Ends