class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int n=intervals.size();
        int tot=0;
        int prev=-1;
        for(int i=0;i<n;i++)
        {
            cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
            if(prev>=intervals[i][1])
            {
                continue;
            }
            else
            {
                prev=intervals[i][1];
                tot++;
            }
        }
        return tot;
    }
};