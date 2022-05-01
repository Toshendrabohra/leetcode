class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int pointer_s = s.size();
        int pointer_ts = t.size();
        
        stack <char> ss;
        for(int i = 0; i < pointer_s ; i++)
        {
            if(s[i]=='#')
            {
                if(!ss.empty())
                    ss.pop();
            }
            else
            {
                ss.push(s[i]);
            }
                
        }
        
         stack <char> st;
        for(int i = 0; i < pointer_ts ; i++)
        {
            if(t[i]=='#')
            {
                if(!st.empty())
                    st.pop();
            }
            else
            {
                st.push(t[i]);
            }
                
        }
        while(!ss.empty() && !st.empty())
        {
            if(ss.top()!=st.top())
                return false;
            ss.pop();
            st.pop();
        }
        
        if(!ss.empty())
            return false;
        if(!st.empty())
            return false;
        return true;
        
    }
};