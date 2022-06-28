class Solution {
public:
    int minDeletions(string s) {
     
        vector<int> freq(26,0);
        map<int,int> fof;
        for(int i = 0; i < s.size(); i++)
        {
            freq[s[i] - 'a'] ++;
        }
        
        for( int i = 0; i < 26; i++)
        {
            fof[freq[i]] ++;
        }
        
        int ans = 0;
        int rem = 0;
        
        for( int i = s.size() ; i > 0; i--)
        {
            if(fof[i]>=1)
            {
                rem += fof[i] - 1;
            }
            
            else if(fof[i] == 0 && rem > 0)
            {
                rem -- ;
            }
            
            ans+= rem;
        }
        
        return ans;
        
        
        
    }
};