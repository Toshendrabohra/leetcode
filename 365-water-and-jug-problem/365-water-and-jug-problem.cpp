class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
      
       vector<int> vis(1e6+1,0);
        queue<int> q;
        q.push(0);
        if(targetCapacity > jug1Capacity + jug2Capacity)
            return false;
            
        while(!q.empty())
        {
            int cur=q.front();q.pop();
            if(cur==targetCapacity)
                return true;
            
            if(cur+jug1Capacity<=1e6 && !vis[cur+jug1Capacity])
            {
                vis[cur+jug1Capacity]=1;
                q.push(cur+jug1Capacity);
            }
            if(cur-jug1Capacity>0 && !vis[cur-jug1Capacity])
            {
                vis[cur-jug1Capacity]=1;
                q.push(cur-jug1Capacity);
            }
             if(cur+jug2Capacity<=1e6 && !vis[cur+jug2Capacity])
            {
                vis[cur+jug2Capacity]=1;
                q.push(cur+jug2Capacity);
            }
            if(cur-jug2Capacity>0&& !vis[cur-jug2Capacity])
            {
                vis[cur-jug2Capacity]=1;
                q.push(cur-jug2Capacity);
            }
        }
        return false;
    }
};