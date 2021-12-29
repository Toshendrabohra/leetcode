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
    void dfs(vector<vector<int>>& vis,vector<vector<int>>& image, int sr, int sc, int newColor,int &n,int &m)
    {
        if(vis[sr][sc])
            return ;
        vis[sr][sc]=1;
     int prev=image[sr][sc];
     image[sr][sc]=newColor;
        for(int i=0;i<4;i++)
        {
        if(valid(sr-dx[i],sc-dy[i],n,m) && image[sr-dx[i]][sc-dy[i]]==prev)
        {
            dfs(vis,image,sr-dx[i], sc-dy[i],newColor,n,m);
        }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        
        int n=image.size(),m=image[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        dfs(vis,image,sr, sc,newColor,n,m);
        return image;
    }
};