class Solution {
public:
    int dp[1001][1001];
    int find(int p1, int p2, vector<int> &nums1, vector<int> &nums2)
    {
        if( p1 >= nums1.size() || p2 >= nums2.size())    
        {
            return 0;
        }
        
        if(dp[p1][p2] != -1)
            return dp[p1][p2];
       
        if(nums1[p1] ==  nums2[p2])
            dp[p1][p2] = 1 + find(p1 + 1, p2 + 1, nums1, nums2);
        else
            dp[p1][p2] = 0;
        
        return dp[p1][p2];
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        for(int i = 0; i <= 1000; i++)
        {
            for(int j = 0; j <= 1000; j++)
                dp[i][j] = 0;
        }
        
        int ans = 0;
        
        for(int i = nums2.size() - 1; i >= 0; i--)
        {
            for(int j = nums1.size() - 1; j >= 0 ; j--)
            {
                if(nums2[i] == nums1[j])
                    dp[i][j] = 1 + dp[i+1][j+1];
                ans = max(ans, dp[i][j]);
            }
        }
        
        return ans;
        
        
    }
};