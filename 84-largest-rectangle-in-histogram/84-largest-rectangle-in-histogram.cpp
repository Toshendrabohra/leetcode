class Solution {
public:
  
    int largestRectangleArea(vector<int>& heights) {
             int n=heights.size();
        vector<int> lmin(n+1),rmin(n+1);
        stack<int> s,f;
  

        int ans=0;
        for(int i=0;i<=n;i++)
        {
              while(!f.empty() && (i==n || heights[f.top()]>=heights[i]))
            {
               int x= f.top();
                  f.pop()   ;
                  int wd=f.empty()?i:(i-f.top()-1);
                  ans=max(ans,wd*heights[x]);
   
            }
          
            f.push(i);
          
        }
            return ans;
    }
};