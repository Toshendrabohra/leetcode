class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        bool poss = false;
        int ans = 0;
        
        int l = -1 , r = 0, sum = 0;
        int n =  nums.size() ;
        
        for( int i = 0; i<n; i++)
        {
            sum += nums[i];
        }
        
        x = sum - x;
        sum = 0;
        
        while(r < n && l < n-1  )
        {
           
            if(sum == x)
            {
                poss = true;
                ans = max(ans, r - l - 1);
                
                sum += nums[r++];
                
            }
            else if( sum < x)
            {
                sum += nums[r++];
            }
            else
            {
                sum -= nums[++l];
            }
        }
        
        while( l < n-1  && sum >= x)
        {
            if(sum == x)
            {
                poss = true;
                ans = max(ans, r - l - 1);
            }
            
            sum -= nums[++l];
        }
        
        if(poss && x>=0)
            return n - ans;
        else
            return -1;
    }
};