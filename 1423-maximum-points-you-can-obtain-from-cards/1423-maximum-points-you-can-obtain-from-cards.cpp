class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> pre(n+1, 0);
        int sum = 0;
        int mn = INT_MAX;
        k = n - k;
        for(int i = 0; i < n; i++)
        {
            pre[i+1] += pre[i] + cardPoints[i];
            
            sum += cardPoints[i];
            
            if(i+1>=k)
            {
                mn = min(mn, pre[i+1] - pre[i+1-k]);
               
            }
        }
        
       return sum - mn;
        
        
    }
};