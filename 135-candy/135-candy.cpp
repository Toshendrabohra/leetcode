class Solution {
public:
    int candy(vector<int>& ratings) {
        
        vector<int> candy(ratings.size(),0);
        int candies = 0;
        int prev = 0;
        int n = ratings.size();
        
        for(int i = 0; i < ratings.size(); i++)
        {
            int x = i+1;
            while(x<n && ratings[x]<ratings[x-1])
                x++;
            int temp = x;
                x--;
            int cur = 1;
            
            while(x>i)
            {
                candies+=cur++;
                x--;
            }
            
            int here = cur;
            
            if(i>0 && ratings[i]>ratings[i-1])
            {
              here = max(here, prev+1) ;
            }
            
            prev = here;
            candies+=here;
            if(temp > i+1)
            {
                i = temp - 1;
                prev = 1;
            }
        }
        
        return candies;
    }
};