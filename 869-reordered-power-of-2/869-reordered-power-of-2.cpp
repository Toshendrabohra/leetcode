class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> count(10,0);
        while(n)
        {
            count[n%10]++;
            n/=10;
        }
        
        long long int x = 1;
        while(x < 1e10)
        {
            vector<int> dum(10,0);
            long long int dash = x;
            while(dash)
            {
                dum[dash%10]++;
                dash/=10;
            }
            
            bool poss = true;
            for(int i = 0; i <= 9; i++)
            {
                if(dum[i] != count[i])
                    poss = false;
            }
            
            if(poss)
                return poss;
            
            x*=2ll;
            
        }
        
        return false;
    }
    
    
};