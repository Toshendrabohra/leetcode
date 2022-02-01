class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx=prices[0];
        int ans=0;
        int n=prices.size();
        for(int i=0;i<n;i++)
        {
            mx=min(mx,prices[i]);
            ans=max(ans,prices[i]-mx);
        }
        return ans;
    }
};