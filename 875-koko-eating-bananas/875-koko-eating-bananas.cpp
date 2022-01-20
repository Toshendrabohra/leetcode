class Solution {
public:
    bool chk(int &mid,vector<int> &piles,int &h)
    {
        int cnt=0;
        int n=piles.size();
        for(int i=0;i<n;i++)
        {
            cnt+=(piles[i]+mid-1)/mid;
        }
        return cnt<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=1e9;
        int ans=r;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(chk(mid,piles,h))
            {
                r=mid-1;
                ans=min(ans,mid);
            }
            else
                l=mid+1;
        }
        return ans;
    }
};