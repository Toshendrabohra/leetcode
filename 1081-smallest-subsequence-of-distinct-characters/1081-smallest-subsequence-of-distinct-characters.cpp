class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last_pos(26,0);
        vector<bool> present(26,0);
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            last_pos[s[i]-'a']=i;
        }
        stack<int> final_s;
        string ans;
        for(int i=0;i<n;i++)
        {
            if(final_s.empty())
            {
                present[s[i]-'a']=true;
                final_s.push(s[i]-'a');
            }
            else
            {
                if(present[s[i]-'a'])
                    continue;
                while(!final_s.empty() && last_pos[final_s.top()]>i && final_s.top()>s[i]-'a')
                {
                    present[final_s.top()]=false;
                    final_s.pop();
                }
                present[s[i]-'a']=true;
                final_s.push(s[i]-'a');
            }
        }
        while(!final_s.empty())
        {
            ans+=final_s.top()+'a';
            final_s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};