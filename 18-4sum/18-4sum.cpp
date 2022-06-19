class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            if(i==0 || nums[i] != nums[i-1])
            for( int j = i+1; j < n; j++)
            {
                if(j==i+1 || nums[j]!=nums[j-1])
                {
                   long long int sum = (long long int)target - (long long int)nums[i] - (long long int)nums[j];

                    int l = j+1, r = n - 1;

                    while(l < r)
                    {
                        if((long long int)nums[l] + (long long int)nums[r] == sum)
                        {
                            cout<<(j)<<" ";
                            ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                            l++;
                            while(l < r && nums[l] == nums[l-1])
                                l++;

                        }
                        else if( (long long int)nums[l] + (long long int)nums[r] < sum)
                        {
                            l++;
                        }
                        else
                            r--;

                    }
                }
            }
        }
        
        return ans;
    }
};