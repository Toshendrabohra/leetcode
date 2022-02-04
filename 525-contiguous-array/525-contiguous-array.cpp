class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum=0;
        map<int,int> m;
        int n=nums.size();
        m[0]=-1;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                sum--;
            else
                sum++;
            if(m.find(sum)!=m.end())
            {
                ans=max(ans,i-m[sum]);
            }
            else
                m[sum]=i;
        }
        return ans;
    }
};