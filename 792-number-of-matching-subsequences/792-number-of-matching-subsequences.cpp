class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> mapped(26);
        
        for( int i = 0; i < s.size(); i++)
        {
            mapped[s[i] - 'a'].push_back(i);
        }
        
        int ans = 0;
        
        for( int i = 0; i < words.size(); i++)
        {
            int prev = -1;
            int flag = 1;
            for( int j = 0; j < words[i].size(); j++)
            {
                
                int nxt = -1;
                if(!mapped[words[i][j] - 'a'].empty())
                {
                nxt = upper_bound(mapped[words[i][j] - 'a'].begin(), mapped[words[i][j] - 'a'].end(), prev) - mapped[words[i][j] - 'a'].begin();
                    if(nxt >= mapped[words[i][j] - 'a'].size() ||  mapped[words[i][j] - 'a'][nxt] < prev)
                        flag = 0;
                    else
                        prev = mapped[words[i][j] - 'a'][nxt] ;
                }
                else
                {
                    flag = 0;
                }
                
                if(!flag)
                    break;
                
            }
            
            ans += flag;
        }
        
        return ans;
    }
};