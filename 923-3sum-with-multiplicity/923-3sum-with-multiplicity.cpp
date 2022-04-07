class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
        int n=arr.size();
        int mod=1e9+7;

        vector<long long int> freq(101,0);
        for(int i=0;i<n;i++)   
        {
            freq[arr[i]]++;
        }
        map<int,int> hash;
        int ans=0;
        for(int i=0;i<=100;i++)
        {
            int l=i,r=100;
            while(l<=r)
            {
                if(l+r==target-i)
                {
                    
                 long long   int freq1=freq[l];
                 long long   int freq2=freq[r];
                    int cnt=1;
                    if(l==i)
                        freq1--;
                    if(r==i)
                        freq2--;
                    if(l==r)
                        freq2--;
                    vector<int> x={l,r,i};
                    sort(x.begin(),x.end());
                   
                    long long int factor=1;

                    if(x[0]==x[1])
                        cnt++;
                    if(x[2]==x[1])
                        cnt++;
                    
                    while(cnt!=1)
                    {
                        factor=factor*cnt;
                        cnt--;
                    }
                    
                    ans=(ans+((freq[i]*freq1*freq2)/factor)%mod)%mod;
                    here:
                   // cout<<i<<" "<<l<<" "<<r<<" "<<(freq[i]*freq1*freq2)/factor<<endl;
                    l++;
                    r--;
                }
                else if(l+r<target-i)
                    l++;
                else
                    r--;
            }
            
        }
        return ans;
    }
};