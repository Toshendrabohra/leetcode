class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> dp(s.size(), 0);
        int n = words[0].size();
        unordered_map<string, int> m;
        vector<int> count(words.size(),0);
        
        for(int i = 0; i < words.size(); i++)
            m[words[i]] = i+1;
        
        for(int i = 0; i < words.size(); i++)
            count[m[words[i]] - 1]++;
        
        for(int i = 0; i < s.size() - n + 1; i++)
        {
            string dum = s.substr(i,n);
            if(m.find(dum) != m.end())
            {
                dp[i+n-1] = m[dum];
            }    
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            map<int,int> hash;
            int tot = 0;
            int l = i+n-1, r = i+n-1;
            
            while(l<s.size() && r<s.size())
            {
               
                
                if(dp[r] != 0 && hash[dp[r] - 1] < count[dp[r] - 1])
                {
                    tot++;
                     hash[dp[r] - 1]++;
                    r+=n;
                }
                else if(dp[r] != 0 && hash[dp[r] - 1] == count[dp[r] - 1])
                {
                    while(l<=r && hash[dp[r] - 1] == count[dp[r] - 1])
                    {
                        hash[dp[l] - 1] --;
                        l += n;
                        tot--;
                    }
                }
                else
                {
                    tot = 0;
                    r+=n;
                    l = r;
                    hash.clear();
                }
                           
            if(tot == words.size())
                {
                    ans.push_back(r - n*(words.size()+1) + 1);
                }
                
            }
            
//             if(tot == words.size())
//                 {
//                     ans.push_back(r - n*words.size() + 1);
//                 }
            
        }
        
        return ans;
        
        
        
    }
};