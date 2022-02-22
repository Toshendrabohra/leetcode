class Solution {
public:
    int titleToNumber(string s)  {
        int ans=0;
        int n=s.size();
        int x=pow(26,n-1);
        for(int i=0;i<n;i++)
        {
            ans+=(s[i]-'A'+1)*x;
            x/=26;
        }
        return ans;
    }
};