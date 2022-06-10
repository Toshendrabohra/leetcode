class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;int ans=0;
    vector<int> a(256,0);
        //cout<<1;
        while( r<s.size())
        {
           
            a[s[r]-' ']++;
                while(l<s.size() && a[s[r]-' ']>1)
                {
                    if(l>=0)
                        a[s[l]-' ']--;
                    l++;
               
                }
            //cout<<l<<" "<<r<<endl;
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};