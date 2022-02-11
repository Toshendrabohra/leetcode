class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l=0;
        int r=0;
        int tot=0;
        vector<int> a(26,0),b(26,0);
        for(int i=0;i<s1.size();i++)
        {
            a[s1[i]-'a']++;
            if(a[s1[i]-'a']==1)
                tot++;
        }
        int cnt=0;
        while(r<s2.size())
        {
          
        if(r>=s1.size())
        {
          b[s2[l]-'a']--;
            if(b[s2[l]-'a']+1==a[s2[l]-'a'])
                cnt--;
            l++;
            
        }  
            b[s2[r]-'a']++;
            if(b[s2[r]-'a']==a[s2[r]-'a'])
                cnt++;
            if(cnt==tot)
                return true;
            r++;
        }
        return false;
    }
};