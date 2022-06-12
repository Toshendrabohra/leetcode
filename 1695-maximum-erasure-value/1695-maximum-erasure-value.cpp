class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = -1, r = 0;
        int sum = 0;
        int ans = 0;
        int n = nums.size(); 
        
        vector<bool> presence(1e4+1, false);
        
        while(r<n && l < n-1)
        {
                if(!presence[nums[r]])
                {
                  
                    sum += nums[r];
                    presence [nums[r++]] = true;
                }
                else
                {
                    while(l<n-1 && presence[nums[r]])
                    {
                        presence[nums[++l]] = false;
                        sum -= nums[l];
                    }
                }
            // cout<<sum<<" "<<l<<" "<<r<<endl;
             ans = max(ans, sum);
        }
        
        return ans;
    }
};