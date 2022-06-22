// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template 

class Solution{
  public:
    // s : given string
    // return the expected answer
    int mod = 1e9 + 7;
    
    long long int power(long long int x, long long int y)
    {
        if(y==0)
        return 1;
        if(x ==  1)
        return 1;
        
        if(y == 1 )
        return x;
        
        long long int r= 1;
        if(y%2)    
        r = x;
        
        long long int z = power(x, y/2);
        
        return (z*z*r)%mod;
    }
    
    int fun(string &s) {
        //code here
        int n = s.size();
        
        long long int a[n+1] , c[n+1];
        a[0] = c[n] = 0;
        for (int i = 0; i < n; i++)
        {
            a[i+1] = a[i] + ((s[i] == 'a' )?1:0);
            //cout<<a[i]<<" ";
        }
        
        for( int i = n - 1; i >= 0; i--)
        {
            c[i] = c[i+1] + ((s[i] == 'c')?1:0);
        }
        
        long long int ans = 0;
        long long int pre = 0;
        long long int tot = 0;
        
        for (int i = 0; i < n; i++)
        {
                if(s[i] == 'b')
                {
                    long long int x = power(2ll,a[i+1]) - 1;
                    
                    ans = (ans + ((x + pre)*(power(2ll,c[i]) - 1))%mod )%mod;
                    
                   // cout<<x + pre <<" "<<c[i]<<" "<<ans<<endl;
                    
                    pre = (x+(2*pre)%mod)%mod;
                }
        }
        
        return ans%mod;
    }
};

// { Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}  // } Driver Code Ends