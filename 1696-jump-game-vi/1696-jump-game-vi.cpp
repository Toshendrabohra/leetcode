class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> q;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(q.empty())
            {
                q.push_back(i);
                continue;
            }
            while(!q.empty() && i-q.front() > k)
            {
                q.pop_front();
            }
            int x = nums[i] + nums[q.front()];
            while(!q.empty() && nums[q.back()] <= x)
            {
                q.pop_back();
            }
            nums[i] = x;
            q.push_back(i);
        }
        
        return nums[q.back()];
    }
};