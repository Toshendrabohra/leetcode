class Solution {
public:
    int find_max(vector<int> &nums,int l,int r, vector<vector<int>> &dp)
    {
         if(dp[l][r]!=-1)
         return dp[l][r];
         int ans=0;
            for(int i=l+1;i<r;i++)
            {
                int left=find_max(nums,l,i,dp);
                int right=find_max(nums,i,r,dp);
                ans=max(ans,nums[i]*nums[l]*nums[r]+left+right);
            }
    return dp[l][r]=ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
       reverse(nums.begin(),nums.end());
        nums.push_back(1);
        reverse(nums.begin(),nums.end());
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
     return  find_max(nums,0,nums.size()-1,dp);
    }
};