class Solution {
public:
    
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int flag=0;
        bool found=false;
        vector<int> holes(6001,0);
        int mx=-1;
        for(int i=0;i<forbidden.size();i++)
            holes[forbidden[i]]=1,mx=max(mx,forbidden[i]);
       
       vector<int> vis(6001,0);
        queue<vector<int>> q;
       // return -1;
        q.push({0,0,0});
        while(!q.empty())
        {
            vector<int> cur=q.front();
            if(cur[0]==x)
                return cur[1];
            q.pop();
            if(cur[2]==0 && cur[0]-b>=0 && vis[cur[0]-b]==0 && holes[cur[0]-b]!=1)
            {
                vis[cur[0]-b]=1;
                q.push({cur[0]-b,cur[1]+1,1});
            }
            if(cur[0]+a<=6000 && !vis[cur[0]+a] && holes[cur[0]+a]!=1 )
            {   vis[cur[0]+a]=1;
                q.push({cur[0]+a,cur[1]+1,0});
            } 
        }
        return -1;
    }
};