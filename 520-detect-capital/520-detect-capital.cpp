class Solution {
public:
    bool detectCapitalUse(string words) {
        int cnt=0;
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            if(words[i]<='Z' && words[i]>='A')
                cnt++;
        }
        
        if(cnt==n || cnt==0 || (cnt==1 && words[0]>='A' && words[0]<='Z'))
            return true;
        return false;
    }
};