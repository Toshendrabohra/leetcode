class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector <int> majo = {0,0};
        vector <int> cnt(2,0);
        if(nums.size() == 1)
            return nums;
        int n = nums.size();
        
        for( int i = 0; i < n; i++)
        {
            if(majo[0] == nums[i])
            {
                cnt[0]++;
            }
            else if(majo[1] == nums[i])
            {
                cnt[1]++;
            }
            else if(cnt[0] == 0)
            {
                   majo[0] = nums[i];
                    cnt[0] = 1;
            }
            else if(cnt[1] == 0)
            {
                    majo[1] = nums[i];
                    cnt[1] = 1;
            }
            else
            {
                cnt[1]--;
                cnt[0]--;
            }
            
          
        }
       
        cnt[0] = cnt[1] = 0;
         for( int i = 0; i < n; i++)
        {
            if(majo[0] == nums[i])
            {
                cnt[0]++;
            }
            else if(majo[1] == nums[i])
            {
                cnt[1]++;
            }
            
            if(cnt[0]<cnt[1])
            {
                swap(cnt[0], cnt[1]);
                swap(majo[0], majo[1]);
            }
        }
       // cout<<cnt[0]<<" "<<cnt[1]<<endl;
        if(cnt[1] <= n/3 )
            majo.pop_back();
        if(cnt[0] <= n/3 )
            majo.pop_back();
        
        return majo;
    }
};