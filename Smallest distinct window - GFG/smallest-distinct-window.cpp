// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    bool chk(int &tot, int &n , string &s, int &mid)
    {
        vector<int> chars(256, 0);
        int cnt = 0;
        for(int i = 0 ; i < n; i++)
        {
            if( i < mid)
            {
                chars[s[i] - 'A']++;
                if(chars[s[i] - 'A'] == 1)
                {
                    cnt++;
                }
            }
            else
            {
                chars[s[i - mid] - 'A']--;
                 if(chars[s[i - mid] - 'A'] == 0)
                {
                    cnt--;
                }
                chars[s[i] - 'A']++;
                 if(chars[s[i] - 'A'] == 1)
                {
                    cnt++;
                }
            }
            
            if(cnt == tot)
            return true;
        }
        return false;
    }
    public:
    int findSubString(string s)
    {
        // Your code goes here 
         int n = s.size();
        int l = 0, r = n;
        vector<int> chars(256,0);
        int tot = 0;
       
         
        for( int  i = 0; i < n; i++)
        {
            
        chars[s[i] - 'A']++;
        if(chars[s[i]-'A'] == 1)
        tot++;
        
        }
        
        int ans = n;
        
        while(l <= r) 
        {
            int mid = (l + r)/2;
            
            if(chk(tot, n, s, mid))
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
       
        
        return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends