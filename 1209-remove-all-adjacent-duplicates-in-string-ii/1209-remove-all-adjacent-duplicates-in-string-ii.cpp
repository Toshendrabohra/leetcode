class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        vector<vector<int>> transformed;
        
        int cnt=1;
        int n=s.size(); 
        char prev=s[0];
        
        for(int i = 1 ; i < n ; i++ )
        {
            if(s[i] == prev)
                cnt++;
            else
            {
                if(cnt%k!=0)
                {
                transformed.push_back({i-1, cnt%k , prev-'a' });
                    cnt=1;
                    prev=s[i];
                }
                else
                {
                 if(!transformed.empty() && transformed.back()[2]== s[i]-'a' )   
                 {
                     cnt=transformed.back()[1]+1;
                     prev=transformed.back()[2]+'a';
                     transformed.pop_back();
                 }
                 else
                 {
                    cnt=1;
                    prev=s[i];
                 }
                }
                
            }
        }
        if(cnt%k!=0)
                {
                transformed.push_back({n-1, cnt%k , prev-'a' });
                    cnt=1;
                }
        string ans;
        
        for(int i = 0 ; i < transformed.size() ; i++)
        {
            while(transformed[i][1]--)
                ans+=transformed[i][2] + 'a';
        }
        
        return ans;
    }
};