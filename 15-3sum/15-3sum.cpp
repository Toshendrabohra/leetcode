class Solution
{
    public:
        vector<vector < int>> threeSum(vector<int> &nums)
        {
            int n = nums.size();
            vector<vector<int>> ans;
            sort(nums.begin(), nums.end());
            
            for (int i = 0; i < n; i++)
            {
                if(i == n-1 || nums[i] != nums[i+1])
                {
                    int target = - nums[i];
                    int l = 0, r = i - 1; 
                    while (l < r)
                    {
                        if(nums[l] + nums[r] == target)
                        {
                            if(ans.empty() || nums[l] !=ans.back()[1] || nums[r] != ans.back()[2])
                            {
                                ans.push_back({nums[i], nums[l], nums[r]});
                            }
                            l++;r--;
                        }
                        else if(nums[l] + nums[r] < target)
                        {
                            l++;
                        }
                        else
                            r--;
                    }
                }                
            }
            
            return ans;
        }
};