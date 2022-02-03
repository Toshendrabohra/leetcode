class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
       map<int,int> m;
        int n=nums1.size();
       for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                    int find=nums3[i]+nums4[j];
                    m[find]++;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                    int find=-nums1[i]-nums2[j];
                    ans+=m[find];
            }
        }
        return ans;
    }
};