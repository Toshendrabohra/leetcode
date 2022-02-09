class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> hash(1e4+1,0);
        int n=nums.size();
        for(int i=0;i<n;i++)
            hash[nums[i]]++;
        vector<int> dp(1e4+1,0);
        for(int i=1;i<10001;i++)
        {
            dp[i]=hash[i]*i;
            if(i>1)
            dp[i]+=dp[i-2];
            dp[i]=max(dp[i],dp[i-1]);
        }
        return dp[10000];
    }
};