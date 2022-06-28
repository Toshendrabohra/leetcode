// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        //code here.
        int l = 0 , r = 0;
        int cnt = 0;
        unordered_map<int, int> m, window;
        int tot = 0;
        for( int i = 0; i < n; i++)
        {
            m[arr[i]] ++;
            if(m[arr[i]] == 1)
            tot++;
        }
        int ans = 0;
        
        while(l < n  )
        {
            while(cnt < tot && r < n)
            {
                window[arr[r]]++;
                if(window[arr[r]] == 1)
                cnt++;
                r++;
            }
            
            if(cnt == tot)
            ans += n - r + 1;
            
            window[arr[l++]]--;
            
            if(window[arr[l - 1]] == 0)
            cnt--;
            
           // cout<<l<<" "<<r<<" "<<ans<<endl;
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
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends