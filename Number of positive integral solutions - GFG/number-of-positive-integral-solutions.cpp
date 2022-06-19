// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
    //#include <bits/stdc++.h>
public:

    int convrt(string s)
    {
        int n = 0;
        for( int i = 0; i < s.size(); i++)
        {
            n*=10;
            n+=s[i] - '0';
            
        }
        return n;
    }
    long memo(int n, int sum)
    {
        if(n == 1 && sum > 0)
        return 1;
        else if(n == 1)
        return 0;
        
        // if(dp[n][sum] != -1)
        //     return dp[n][sum];
        
        // dp[n][sum] = 0;
        long x = 0;
        for(int i = 1; i <= sum - n + 1; i++)
        {
            //dp[n][sum] 
            x+= memo(n-1, sum - i);
        }
        
        return x;
    }
    long posIntSol(string s)
    {
        int num;
        int n = 0;
        for( int i = 0; i < s.size(); i++)
        {
            if(s[i] == '+')
            n++;
            else if(s[i] == '=')
            {
                n++;
                num = convrt (s.substr(i+1));
                break;
            }
        }
       // cout<<num;
       // vector<vector<long>> dp(n+1, vector<long> (num+1, -1));
        
        return memo(n, num);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.posIntSol(s)<<endl;
    }
    return 0;
}
  // } Driver Code Ends