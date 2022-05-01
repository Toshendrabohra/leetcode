class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int pointer_s = s.size()-1;
        int pointer_ts = t.size() - 1;
        
       while( pointer_s >= 0 &&  pointer_ts >= 0)
        {
            if(pointer_s>=0 && s[pointer_s] == '#')
            {
                int cnt = 1;
                pointer_s--;
                
                while(cnt && pointer_s>=0)
                {
                    if(s[pointer_s]=='#')
                        cnt++;
                    else
                        cnt--;
                    pointer_s--;
                }
                    
            }
            else if(pointer_ts >= 0 && t[pointer_ts] == '#')
            {
                int cnt=1;
                pointer_ts--;
                
                while(cnt && pointer_ts>=0)
                {
                    if(t[pointer_ts]=='#')
                        cnt++;
                    else
                        cnt--;
                    pointer_ts--;
                }
                   
              
            }
            else if(pointer_ts >= 0 && pointer_s >= 0 && t[pointer_ts] == s[pointer_s])
            {
                pointer_ts--;
                pointer_s--;
            }
            else
                break;
        }
        
        while(pointer_s>=0 && s[pointer_s]=='#')
        {
                int cnt = 1;
                pointer_s--;
                
                while(cnt && pointer_s>=0)
                {
                    if(s[pointer_s]=='#')
                        cnt++;
                    else
                        cnt--;
                    pointer_s--;
                }
        }
        
        while(pointer_ts>=0 && t[pointer_ts]=='#')
        {
                int cnt=1;
                pointer_ts--;
                
                while(cnt && pointer_ts>=0)
                {
                    if(t[pointer_ts]=='#')
                        cnt++;
                    else
                        cnt--;
                    pointer_ts--;
                }
        }
              // pointer_ts=cnt;
        
        if(pointer_s<=-1 && pointer_ts<=-1)
            return true;
        cout<<pointer_s<<" "<<pointer_ts;
        return false;
    }
};