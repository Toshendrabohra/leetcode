class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string s) {
        vector<string> ans;
        for( int i = 0; i < words.size(); i++)
        {
            map<char, char> forw,back;
            int flag = 1;
            if(s.size() != words[i].size())
                continue;
           
            for(int j = 0; j < words[i].size(); j++)
            {
                if(forw.find(words[i][j]) == forw.end() && back.find(s[j])== back.end())
                {
                    forw[words[i][j]] = s[j];
                    back[s[j]] = words[i][j];
                }
                else if(forw[words[i][j]] != s[j] || back[s[j]] != words[i][j])
                {
                    flag = 0;
                    break;
                }
            }
            
            if(flag)
                ans.push_back(words[i]);
        }
        
        return ans;
    }
};