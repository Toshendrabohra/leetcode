class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> closest;
        for(int i=0;i<points.size();i++)
        {
            closest.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],i});
        }
         vector<vector<int>> ans;
        while(k--)
        {
            ans.push_back(points[closest.top().second]);
            closest.pop();
        }
        return ans;
    }
};