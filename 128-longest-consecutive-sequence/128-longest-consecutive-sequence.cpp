class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m, visited;
        int ans = 0;
        
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]] = 1;
        }
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(!visited[nums[i]])
            {
                int l = nums[i] - 1;
                int r = nums[i] + 1;
                int cnt = 1;
                while(m[l] == 1)
                {
                    cnt++;
                    visited[l] = 1;
                    l--;
                }
                while(m[r] == 1)
                {
                    cnt++;
                    visited[r] = 1;
                    r++;
                }
                
                ans = max(ans, cnt);
            }
        }
        
        return ans;
        
    }
};