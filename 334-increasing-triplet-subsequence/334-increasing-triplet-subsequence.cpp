class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++)
        {
            int x = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();

            if (x != dp.size())
                dp[x] = nums[i];
            else
                dp.push_back(nums[i]);
        }

        return dp.size()>=3;
    }
};