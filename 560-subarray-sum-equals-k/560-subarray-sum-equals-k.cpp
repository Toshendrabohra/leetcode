class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int l=0,r=0;
        int n=nums.size();
        int ans=0;
        int sum=0;
        map<int,int> m;
        m[0]=1;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            ans+=m[sum-k];
            m[sum]++;
        }
        return ans;
    }
};