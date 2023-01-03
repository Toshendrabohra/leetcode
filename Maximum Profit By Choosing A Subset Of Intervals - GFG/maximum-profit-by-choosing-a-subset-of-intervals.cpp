//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    static bool comp(const vector<int> &a , const vector<int> &b) 
    { 
        if(a[1] == b[1])  return a[0] < b[0];  
        return a[1] < b[1]; 
    }

    int maximum_profit(int n, vector<vector<int>> &intervals) {
        // Write your code here.
        
        sort(intervals.begin(), intervals.end(), comp);
        
        vector<int> dp(1e5+2, 0);
        
        int indx = 0;
        for(int i = 1 ; i <= 1e5; i++)
        {
            dp[i] = max(dp[i], dp[i-1]);
            while(indx < n && intervals[indx][1] == i)
            {
                dp[i] = max(dp[intervals[indx][0]] + intervals[indx][2] , dp[i]);
                indx++;
            }
        }
        
        return dp[1e5];
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends