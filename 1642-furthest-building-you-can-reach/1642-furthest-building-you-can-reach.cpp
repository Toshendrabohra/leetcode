class Solution {
public:
    bool chk(vector<int>& heights, int bricks, int ladders, int mid)
    {
        vector<int>  breq;
        
        for( int i = 1; i <= mid; i++)
        {
            if(heights[i] > heights[i-1])
                breq.push_back(heights[i] - heights[i-1]);
        }
        
        sort(breq.begin(), breq.end());
        while(ladders-- && !breq.empty())
        {
            breq.pop_back();
        }
        
        while(bricks && !breq.empty())
        {
            int x = breq.back();
            if(x<=bricks)
            {
                breq.pop_back();
                bricks -= x;
            }
            else
                break;
        }
        
        return breq.empty();
        
    }
    
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int ans = 0;
        int n = heights.size();
        int l = 0, r = n-1;
        
        while( l<= r)
        {
                int mid = (l+r)/2;
            if(chk(heights, bricks, ladders, mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        
        return ans;
    }
};