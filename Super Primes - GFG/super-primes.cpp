// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> prime;
	int superPrimes(int n)
	{
	    // Your code goes here
	    int cnt=0;
	    prime.clear();
	    prime.resize(n+1,1);
	    prime[0]=0;
	    prime[1]=0;
	    for(int i=2;i*i<=n;i++)
	    {
	        if(prime[i])    
	        {
	            
	            for(int j=i*i; j<=n ; j+=i)
	            prime[j]=0;
	        }
	    }
	    for(int i=5;i<=n;i++)
	    {
	    if(prime[i] && prime[i-2])
	    cnt++;
	    }
	    return cnt;
	}
};

// { Driver Code Starts.

int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
   		Solution ob;
   		cout << ob.superPrimes(n) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends