class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
       vector<int> dp(cost.size(), 0);
        int prev = cost[0];
        int cur = cost[1];
        for( int i = 2; i < cost.size(); i++)
        {
            
            int temp = min(cur,prev) + cost[i];
            prev = cur;
            cur = temp;
        }
       // int n = cost.size();
        return min(prev, cur);
    }
};