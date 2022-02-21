class Solution {
public:
    int majorityElement(vector<int>& nums) {
     int cnt=0;
        int majority=-1;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(majority==nums[i])
                cnt++;
            else
                cnt--;
            if(cnt==-1)
                majority=nums[i],cnt=1;
        }
        return majority;
    }
};