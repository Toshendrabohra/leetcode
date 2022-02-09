class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int,int> m;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(k==0)
            {
                ans+=(m[nums[i]]-1>0)?1:0;
                m[nums[i]]=1;
                continue;
            }
            if(m[nums[i]-k])
                ans++;
            m[nums[i]-k]=0;
        }
        return ans;
    }
};