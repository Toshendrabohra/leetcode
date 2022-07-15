class Solution {
public:
     int dx[4]={-1,0,1,0};
     int dy[4]={0,-1,0,1};
      
    bool valid(int x,int y,int &n,int &m)
    {
        if(x>=0 && y>=0 && x<n && y<m)
        return true;
        return false;
    }
     int dfs(vector<vector<int>>& image, int sr, int sc,int &n,int &m)
    {
           image[sr][sc]=2;
           int cnt=1;
        for(int i=0;i<4;i++)
        {
        if(valid(sr-dx[i],sc-dy[i],n,m) )
        {
            if(image[sr-dx[i]][sc-dy[i]]==1)
             cnt+= dfs(image,sr-dx[i], sc-dy[i],n,m);
        }
        }
           return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& image) {
          int ans=0;
          int n=image.size(),m=image[0].size();
         int cnt=0;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
         {
                 if(image[i][j]==1)
                 cnt=max(cnt,dfs(image,i,j,n,m));
         }
        return cnt;
    }
};

     
  
    
