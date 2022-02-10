class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> hash(1e4+1,0);
        int n=nums.size();
        for(int i=0;i<n;i++)
            hash[nums[i]]++;
        int ans=0,prev=0,prevdash=0;
        for(int i=1;i<10001;i++)
        {
            int dum=hash[i]*i+prevdash;
            prevdash=max(prevdash,prev);
            ans=max(dum,ans);
            prev=max(prev,dum);
        }
        return ans;
    }
};