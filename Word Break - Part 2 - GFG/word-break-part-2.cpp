// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void make(int cur, string &s, string dum, vector<string> &ans, unordered_map<string,int> &m)
    {
        if(cur == s.size())
        {
            dum.pop_back();
            ans.push_back(dum);
            return;
        }
        
        
        string x;
        
        for(int i = cur; i < s.size(); i++)
        {
            x += s[i];
            dum+=s[i];
            if(m.find(x) !=m.end())
            {
                dum+=' ';
                make(i + 1, s, dum, ans, m);
                dum.pop_back();
            }
        }
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        unordered_map<string,int> m;
        for( int i = 0; i < n; i++)
        {
            m[dict[i]]  = 1;
        }
        
        vector<int> dp(s.size()+1, -1);
        dp[0] = 0;
        for( int i = 0; i < s.size(); i++)
        {
            if(dp[i]!=-1)
            {
                string dum;
                for( int j = i; j < s.size(); j++)
                {
                    dum += s[j];
                    
                    if(m.find(dum) != m.end())
                    {
                        dp[j+1] = i;
                    }
                }
            }
        }
       
        int last = s.size();
        vector<string> ans;
        
        string dum;
        make(0, s, dum, ans, m);
        
       
       // reverse(ans.begin(), ans.end());
              
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends