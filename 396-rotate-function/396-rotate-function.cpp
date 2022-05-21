class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int ans=0;
        long long int sum=0;
        long long int cur_val=0;
        for(int i = 0; i < nums.size() ; i++)
        {
            sum+=nums[i];
            cur_val+=nums[i]*i;
        }
        
        ans=cur_val;
        
        for(int i = nums.size() - 1; i >= 0 ; i--)
        {
            cur_val+=sum;
            cur_val-=nums[i]*nums.size();
            ans=max(ans,(int)cur_val);
        }
        
        return ans;
    }
    
};