class Solution {
public:
    int trap(vector<int>& height) {
       // stack<int> rmex;
        int n = height.size();
        vector<int> rmex_i(n);
        int rmex = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            rmex = max(rmex, height[i]);
            
            rmex_i[i] = rmex;
        }
        
        int lmex = 0;
        int tot = 0;
        
        for( int i = 0; i < n; i++)
        {
            lmex = max(lmex, height[i]);
            
            tot += min(lmex, rmex_i[i]) - height[i];
        }
        
        return tot;
        
    }
};