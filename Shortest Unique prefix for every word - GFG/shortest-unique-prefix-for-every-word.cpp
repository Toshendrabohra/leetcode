// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Trie {
public:
        vector<vector<int>> trie;
        int node=0;
        vector<int> nodecnt;
    Trie() {
        trie.clear();
        nodecnt.clear();
        node=0;
        trie.push_back(vector<int>(26,-1));
        nodecnt.push_back(0);
    }
    
    void insert(string word) {
        int n=word.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(trie[cnt][word[i]-'a']==-1)
            {
                trie.push_back(vector<int>(26,-1));
                nodecnt.push_back(0);
                trie[cnt][word[i]-'a']=++node;
            }
            
            cnt=trie[cnt][word[i]-'a'];
            nodecnt[cnt]++;
        }
        
    }
    
 
};

class Solution
{
    public:
    void make_ans(vector<string> &ans,string s,string &f,int cnt,Trie &dict,int pos)
    {    s.push_back(f[pos]);
        if(dict.nodecnt[cnt]==1)
        {
        ans.push_back(s);
        return;
        }
               
                make_ans(ans,s,f,dict.trie[cnt][f[pos+1]-'a'],dict,pos+1);
                
        
    }
    vector<string> findPrefixes(string arr[], int n)
    {
        Trie dict;
        for(int i=0;i<n;i++)
        {
            dict.insert(arr[i]);
        }
    vector<string> ans;
    string s;
    for(int i=0;i<n;i++)
    make_ans(ans,s,arr[i],dict.trie[0][arr[i][0]-'a'],dict,0);
    return ans;
    }
   
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}
  // } Driver Code Ends