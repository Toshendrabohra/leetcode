class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans=0;
        int n=nums.size();
        deque<int> max_d,min_d;
        int last=-1;
        for(int i=0;i<n;i++)
        {
            while(!max_d.empty() && nums[max_d.back()]<nums[i])
                max_d.pop_back();
            while(!min_d.empty() && nums[min_d.back()]>nums[i])
                min_d.pop_back();
            max_d.push_back(i);
            min_d.push_back(i);
            while(!max_d.empty() && !min_d.empty() && nums[max_d.front()]-nums[min_d.front()]>limit)
            {
                if(max_d.front()<min_d.front())
                {
                    last=max(last,max_d.front());
                    max_d.pop_front();
                }
                else
                {
                    last=max(last,min_d.front());
                    min_d.pop_front();
                }
            }
            if(!max_d.empty() && !min_d.empty())
            ans=max(ans,i-last);
        }
        return ans;
    }
};