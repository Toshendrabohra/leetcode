class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> psum(1002,0);
        for(int i=0;i<trips.size();i++)
        {
            psum[trips[i][1]]+=trips[i][0];
            psum[trips[i][2]]-=trips[i][0];
        }
        for(int i=0;i<=1000;i++)
        {
            if(i>0)
                psum[i]+=psum[i-1];
            if(psum[i]>capacity)
                return false;
            
        }
        return true;
    }
    
};