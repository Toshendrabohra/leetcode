class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[1] > b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), comp);
        int ans = 0;
        
        for( int i = 0; i < boxTypes.size(); i++)
        {
            int loaded = min(truckSize, boxTypes[i][0]);
            ans += loaded*boxTypes[i][1];
            truckSize -= loaded;
        }
        
        return ans;
    }
};