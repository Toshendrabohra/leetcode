class Solution {
public:
    int smallestRepunitDivByK(int k) {
        unordered_set<int> seen;
        int r=0;
        for(int i=1;;i++)
        {
            r=(r*10+1)%k;
            if(r==0)
                return i;
            else if(seen.count(r))
                return -1;
            seen.insert(r);
        }
        
    }
};