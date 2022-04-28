class Solution {
public:
    bool chk(int x, int y, int n, int m)
{
    if (x >= 0 && x < n && y >= 0 && y < m)
        return true;
    return false;
}
int minimumEffortPath(vector<vector<int>> &heights)
{
    int row = heights.size();
    int col = heights[0].size();

    vector<vector<int>> dis(row, vector<int>(col, -1));
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> p;
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    p.push({0, 0, 0});
    dis[0][0] = 0;

    while (!p.empty())
    {
        int x = p.top()[1];
        int y = p.top()[2];
        int cur_dis = p.top()[0];
        p.pop();

        //cout<<x<<" "<<y<<" "<<cur_dis<<endl;
        if (x == row - 1 && y == col - 1)
            return cur_dis;

        for (int i = 0; i < 4; i++)
        {
            int cur_x = x + dx[i];
            int cur_y = y + dy[i];
            
            
            if (chk(cur_x, cur_y, row, col) && (dis[cur_x][cur_y] == -1 || max( cur_dis , abs(heights[x][y] - heights[cur_x][cur_y])) < dis[cur_x][cur_y]))
            {
                //cout<<cur_x<<" "<<cur_y<<endl;
                dis[cur_x][cur_y] = max( cur_dis , abs(heights[x][y] - heights[cur_x][cur_y]));
                p.push({dis[cur_x][cur_y], cur_x, cur_y});
            }
        }
        cout<<endl;
    }

    return -1;
}

    
                              


    
};