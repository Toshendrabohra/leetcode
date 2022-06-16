class Solution {
public:
    
    string longestPalindrome(string s) {
      
        int mx=0,start;
        int n=s.size();
         string ans;
        for(int i=0;i<n;i++)
        {
        int center=i;
            int l=i,r=i;
            int x=0,xx;
            while(l>=0 && r<n && s[l]==s[r])
            {xx=l;
                x=r-l+1;
                l--;r++;
            }
            if(x>mx)
            {
                mx=x;
                start=xx;
            }
            
            l=i;r=i+1;
            
            if(r<n && s[l]==s[r])
            {
                      x=0;xx;
                while(l>=0 && r<n && s[l]==s[r])
                {xx=l;
                    x=r-l+1;
                    l--;r++;
                }
                if(x>mx)
                {
                    mx=x;
                    start=xx;
                }
            
            }
        }
        for(int i=start;i<start+mx;i++)
            ans+=s[i];
        return ans;
    }
};