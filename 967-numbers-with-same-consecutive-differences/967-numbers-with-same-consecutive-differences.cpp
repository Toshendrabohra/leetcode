class Solution {
public:
    void count(vector<int> &ans, int n, int k, long long int s, int len)
    {
        if(len == n)
        {
            ans.push_back(s);
            return;
        }
        
        if( s%10 + k <= 9 )
            count(ans, n, k, s*10+ (s%10+k), len + 1);
        
        if( s%10 - k >= 0 && k != 0)
            count(ans, n, k, s*10+ (s%10-k), len + 1);
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        
        if(n >= 1)
        for(long long int i = 1; i <= 9;i++)
        {
        count(ans, n, k, i, 1);
        }
        
        return ans;
    }
};