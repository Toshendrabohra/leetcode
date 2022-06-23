// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int start[], int end[], int n)
    {
    	// Your code here
    	vector<vector<int>> s;
        
        for( int i = 0; i < n; i++)
        {
            s.push_back({start[i], i});
        }
        
        sort(s.begin(), s.end());
        
        priority_queue<int> p;
        p.push(-end[s[0][1]]);
        
        for( int i = 1; i < n; i++)
        {
            int x = -p.top();
            if(s[i][0] > x)
            {
                p.pop();
              
            }
              p.push(-end[s[i][1]]);
        }
        
        return p.size();
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends