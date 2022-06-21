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
        int sum = 0;
        
        priority_queue<int, vector<int>, greater<int>> p;
        for(int i = 1; i < n; i++)
        {
            if(heights[i] - heights[i-1] > 0)
            {
                p.push(heights[i] - heights[i-1]);
            }
            
            if(p.size() > ladders)
            {
                sum += p.top();
                p.pop();
            }
            
            if(sum>bricks)
                break;
            
            ans = i;
            
        }
        
        return ans;
    }
};