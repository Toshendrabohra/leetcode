class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans=0;
        int n=nums.size();
        set<pair<int,int>> s;
        int last=-1;
        for(int i=0;i<n;i++)
        {
            s.insert({nums[i],i});
            while((*s.rbegin()).first-(*s.begin()).first>limit)
            {
                s.erase({nums[last+1],last+1});
                last++;
            }
            ans=max(ans,i-last);
        }
        return ans;
    }
};