class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt= 0;
        
        for(int i =1; i < nums.size(); i++)
        {
            if(nums[i - 1] > nums[i] && cnt == 0)
            {
                int prev , last ;
                if(i == 1)
                    prev = -1e5;
                else
                    prev = nums[i-2];
                
                if(i == nums.size() - 1)
                    last = 1e5;
                else
                    last = nums[i+1];
                if(prev<=nums[i])
                    nums[i - 1 ] = nums[i];
                else if(last >= nums[i-1])
                    nums[i] = nums[i-1];
                else
                    return false;
                cnt++;
            }
            else if(nums[i-1] > nums[i])
                return false;
        }
        
        return true;
    }
};