class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> keys;
        keys.push(0);
        int n=rooms.size();
        vector<int> vis(n+1,0);
        while(!keys.empty())
        {
            int cur=keys.front();
            keys.pop();
            if(vis[cur])
                continue;
            vis[cur]=1;
            for(auto &i:rooms[cur])
                keys.push(i);
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
               // cout<<i;
                return false;
            }
        }
        return true;
    }
};