// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
  public:
    string arrangeString(string str)
    {
        //code here.
        vector<int> a(26,0);
        int sum=0;
        int n=str.size();
        for(int i=0;i<n;i++)
        {
            if(str[i]>='A' && str[i]<='Z')
            a[str[i]-'A']++;
            else
            sum+=str[i]-'0';
        }
        string ans;
        for(int i=0;i<26;i++)
        {
            while(a[i]--)
            {
                ans+='A'+i;
            }
        }
        ans+=to_string(sum);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.arrangeString(s) << endl;
    }
return 0;
}

  // } Driver Code Ends