class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prev = prices[0];
        int ans = 0;
        
        for(int i = 0; i < prices.size(); i++)
        {
            if(prices[i] > prev)
                ans += prices[i] - prev, prev = prices[i];
            else
                prev = min(prices[i], prev);
        }
        
        
        return ans;
    }
};