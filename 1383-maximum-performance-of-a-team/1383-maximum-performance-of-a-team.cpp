class Solution {
public:
 long long int mod = 1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector<vector<int>> sorted;
        for(int i = 0; i < n; i++)
        {
            sorted.push_back({efficiency[i], speed[i]});
        }
        
        sort(sorted.begin(), sorted.end());
        
        priority_queue<int, vector<int>, greater<int>> p;
        
        
      long long  int ans = 0;
      long long  int sum = 0;
        for(int i = n -1; i >= 0; i--)
        {
          
            
            if(p.size() >= k)
                sum = (sum - p.top()),p.pop();
            p.push(sorted[i][1]);
            sum = (sum + sorted[i][1]);
            ans = max(ans, (sum*sorted[i][0]));
        }
        
        return ans%mod;
        
    }
};