// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<vector<int>> s;
        
        for( int i = 0; i < n; i++)
        {
            s.push_back({start[i], i});
        }
        
        sort(s.begin(), s.end());
        
        int endt = 0;
        int cnt = 0;
        for( int i = 0; i < n; i++)
        {
            if(s[i][0] > endt)
            {
                endt = end[s[i][1]];
                cnt++;
            }
            else
            {
                endt = min(endt, end[s[i][1]]);
            }
        }
        
        return cnt;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends