class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> dp;
        dp.push_back(1e5);

        for (int i = 0; i < nums.size(); i++)
        {
            int x = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();

            if (x != dp.size())
                dp[x] = nums[i];
            else
                dp.push_back(nums[i]);
        }

        return dp.size();
    }
};