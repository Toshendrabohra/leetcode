class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int ans=0;
        int n=a.size();int l=0;int r=1;
        while(l<n-1 && r<n)
        {
            while(r<n && a[l+1]-a[l]==a[r]-a[r-1])
            {
                r++;
            }
            r--;
            if(r-l+1>=3)
            {
                int len=r-l+1;
                ans+=((len+1)*(len))/2;
                ans-=len;
                len--;
                ans-=len;
            }
            l=r;
            r++;
        }
        return ans;
    }
};