class Solution {
public:
    int numberOfSteps(int n) {
        
        if(n==0)
            return 0;
        else if(n%2)
            return 1+numberOfSteps(n-1);
        else
            return 1+numberOfSteps(n/2);
    }
    
};