class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        int n=num.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
                while(cnt<k && !s.empty() && s.top()>num[i])
                    s.pop(),cnt++;
                if(!(s.empty() && num[i]=='0'))
                s.push(num[i]);
        }
        string ans;
        while(cnt++<k && !s.empty())
            s.pop();
        while(!s.empty())
            ans+=s.top(),s.pop();
        if(ans.empty())
            ans+='0';
            
        reverse(ans.begin(),ans.end());
        return ans;
    }
};