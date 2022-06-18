class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int indx = n - 1;
        int rotate = 0;
        for( int i = n - 2; i >=0; i--)
        {
            if(nums[i] < nums[indx])
            {
                rotate = i +1 ;
                
                indx = n - 1;
                while(indx >= 0 && nums[indx] <= nums[i])
                    indx --;
                swap(nums[i],nums[indx]);
                break;
            }
            else
                indx = i;
        }
        
        if(n > 1)
        reverse(nums.begin() + rotate , nums.end());
    }
};