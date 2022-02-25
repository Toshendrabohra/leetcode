class Solution {
public:
    int compareVersion(string v1, string v2) {
        int l=0;
        int r=0;
        int n=v1.size();
        int m=v2.size();
        while(l<n || r<m)
        {
            int x=0;
            int y=0;
            while(l<n && v1[l]!='.')
            {
                x=10*x+v1[l++]-'0';
            }
             while(r<m && v2[r]!='.')
            {
                y=10*y+v2[r++]-'0';
            }
            if(x<y)
                return -1;
            else if(x>y)
                return 1;
            l++;r++;
        }
        
        return 0;
    }
};