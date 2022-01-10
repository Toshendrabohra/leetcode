class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size()<b.size())
            swap(a,b);
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string ans;
        int extra=0;
        for(int i=0;i<b.size();i++)
        {
            ans+=(a[i]-'0'+b[i]-'0'+extra)%2+'0';
            extra=(a[i]-'0'+b[i]-'0'+extra)/2;
        }
        for(int i=b.size();i<a.size();i++)
        {
            ans+=(a[i]-'0'+extra)%2+'0';
            extra=(a[i]-'0'+extra)/2;
        }
        if(extra)
            ans+='1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};