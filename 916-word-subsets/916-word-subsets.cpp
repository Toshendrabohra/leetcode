class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> minuni(26, 0);
        for(int i = 0; i < words2.size();i++)
        {
            vector<int> dum(26, 0);
            for( int j = 0; j < words2[i].size(); j++)
            {
                dum[words2[i][j] - 'a']++;
            }
            for(int j = 0; j < 26; j++)
                minuni[j] = max(minuni[j], dum[j]);
        }
        
        vector<string> ans;
        for(int i = 0 ; i < words1.size(); i++)
        {
            vector<int> dum(26,0);
            for(int j = 0; j < words1[i].size(); j++)
            {
                dum[words1[i][j] - 'a']++;
            }
            int flag = 1;
            for(int j = 0; j < 26; j++)
            {
                if(dum[j]<minuni[j])
                    flag = 0;
            }
            
            if(flag)
                ans.push_back(words1[i]);
        }
        
        return ans;
    }
};