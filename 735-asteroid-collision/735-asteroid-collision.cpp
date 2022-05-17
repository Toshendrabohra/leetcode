class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s,dum;
        queue<int> q;
        
        int n=asteroids.size();
        
        vector<int> ans;
        
        for( int i = 0; i< n ; i++)
        {
            
            int flag=0;
            
            if(asteroids[i]<0)    
            {   
                while(!ans.empty() && ans.back()>=0 && ans.back()<=abs(asteroids[i]))
                {
                    if(ans.back()==abs(asteroids[i]))
                    {
                        flag++;
                        ans.pop_back();
                        break;
                    }
                    ans.pop_back();
                }
                if(!ans.empty() && ans.back()>0)
                    flag++;
            }
            
            if(flag==0)
                ans.push_back(asteroids[i]);
        }
        
        
       
        
        return ans;
    }
};