class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur=0;
        int cnt=0;
        int cur_ele=-1000000;
        int n=nums.size()        ;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==cur_ele)
            {
                if(cnt==2)
                    continue;
                cnt++;
                
            }
            else
            {
               cnt=1;
                cur_ele=nums[i];
            }
            nums[cur++]=nums[i];
        }
        return cur;
    }
};