class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<vector<int>> sorted;
        
        for( int i = 0; i < ratings.size(); i++)
        {
            sorted.push_back({ratings[i], i});
        }
        
        sort(sorted.begin(), sorted.end());
        
        vector<int> cand(sorted.size(),0);
        int candies = 0;
        for(int i = 0; i < sorted.size(); i++)
        {
            int indx = sorted[i][1];
            int l = 0, r= 0;
            if(indx<sorted.size()-1 && ratings[indx]>ratings[indx+1])
                r = cand[indx+1];
            if(indx>0 && ratings[indx]>ratings[indx-1])
                l = cand[indx-1];
            cand[indx] = max(r,l) + 1;
           // cout<<indx<<" "<<cand[indx]<<endl;
            candies += cand[indx];
        }
        
        return candies;
    }
};