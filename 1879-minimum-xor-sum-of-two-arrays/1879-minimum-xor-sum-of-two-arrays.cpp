class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
     int n=nums2.size();
        vector<int> xorab((1<<n),-1);
        xorab[0]=0;
        for( int mask = 1; mask < (1<<n) ; mask++)
        {
            int x=__builtin_popcount(mask);
            xorab[mask] = INT_MAX;
            for(int i=0; i< n ; i++)
            {
                if( (mask&(1<<i)) != 0  && xorab[mask^(1<<i)] != -1 && xorab[mask^(1<<i)] != INT_MAX)
                {
                    xorab[mask] = min(xorab[mask] , xorab[mask^(1<<i)]+ (nums1[x-1]^nums2[i]));
                    //cout<<mask<<" "<<(xorab[mask^(1<<i)])<<" "<<(nums1[x-1]^nums2[i])<<endl;
                }
                
            }
            //cout<<xorab[mask]<<endl;
        }
        
        return xorab[(1<<n)-1];
    }
};