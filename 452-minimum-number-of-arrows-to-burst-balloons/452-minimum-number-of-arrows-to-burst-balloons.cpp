class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int cnt=1;
        int end=points[0][1];
        sort(points.begin(),points.end());
        for(int i=0;i<points.size();i++)
        {
                if(points[i][0]>end)
                {
                    end=points[i][1];
                    cnt++;
                }
                else
                {
                    end=min(end,points[i][1]);
                }
            
        }
        return cnt;
    }
};