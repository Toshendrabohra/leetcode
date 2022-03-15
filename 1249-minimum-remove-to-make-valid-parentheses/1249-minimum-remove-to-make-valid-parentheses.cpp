class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        stack<int> lifo;
        int len=s.size();
        for(int i=0;i<len;i++)
        {
            ans+=s[i];
            if(s[i]=='(' )
            {
                lifo.push(ans.size()-1);
            }
            else if(s[i]==')')
            {
                if(lifo.empty())
                {
                    ans.pop_back();
                }
                else
                    lifo.pop();
            }
        }
        string f_ans;
        len=ans.size();
        for(int i=len-1;i>=0;i--)
        {
            if(!lifo.empty() && lifo.top()==i)
                lifo.pop();
            else
                f_ans+=ans[i];
        }
        reverse(f_ans.begin(),f_ans.end());
        return f_ans;
    }
};