class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int x = 1;
        int n = nums.size();
        for ( int i = 1; i < n; i++)
        {
            if(nums[i-1] != nums[i])
            {
                nums[x++] = nums[i];
            }
        }
        
        return x;
    }
};