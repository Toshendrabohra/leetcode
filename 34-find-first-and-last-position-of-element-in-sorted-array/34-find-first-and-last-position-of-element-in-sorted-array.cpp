class Solution {
public:
    int bin1(vector<int>& nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        
        int ans = -1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[mid] == target)
            {
                ans = mid;
                r = mid - 1;
            }
            else if(nums[mid] > target)
            {
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        
        return ans;
    }
    
    int bin2(vector<int>& nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        
        int ans = -1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[mid] == target)
            {
                ans = mid;
                l = mid + 1;
            }
            else if(nums[mid] > target)
            {
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = bin1(nums, target);
        int r = bin2(nums, target);
        
        return {l, r};
    }
};