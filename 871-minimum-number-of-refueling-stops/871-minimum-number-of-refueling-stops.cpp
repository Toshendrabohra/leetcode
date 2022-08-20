class Solution {
public:
    int minRefuelStops(int target, int s, vector<vector<int>>& stations) {
     
        int ans = 0;
        priority_queue<int> p;
        int prev = 0;
        for(int i = 0; i < stations.size(); i++)
        {
            
                while(!p.empty() && stations[i][0] - prev > s)
                {
                    ans++;
                    s += p.top();
                    p.pop();
                }
                
                if(stations[i][0] - prev > s)
                    return -1;
            
            s -= (stations[i][0] - prev);
            prev = stations[i][0];
            p.push(stations[i][1]);
        }
        
        while(!p.empty() && target - prev > s)
        {
                     ans++;
                    s += p.top();
                    p.pop();
        }
        
                        if(target - prev > s)
                            return -1;
        
        return ans;
    }
};