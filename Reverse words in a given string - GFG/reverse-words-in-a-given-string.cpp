// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        string ans,individual;
        int n=S.size();
        reverse(S.begin(),S.end());
        
        for(int i=0;i<n;i++)
        {
            if(S[i]=='.')
            {
                reverse(individual.begin(),individual.end());
                ans+=individual;
                ans+='.';
                individual="";
            }
            else
            {
                individual+=S[i];
            }
        }
        reverse(individual.begin(),individual.end());
                ans+=individual;
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
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends