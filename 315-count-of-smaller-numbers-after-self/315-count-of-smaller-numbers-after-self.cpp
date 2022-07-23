#define ff first
#define ss second

class Solution {
public:
    
    vector<int> ans;
    void merge(vector<pair<int, int>> &v, int s, int m, int e){
        int size = e - s + 1, p = m + 1;
        
        vector<pair<int, int>> sub(size);
        int cnt = 0, idx = 0, idx1 = s;
        
        while(s <= m and p <= e){
            if(v[s].ff > v[p].ff){
                cnt++;
                sub[idx++] = v[p++];
            }
            else {
                ans[v[s].ss] += cnt;
                sub[idx++] = v[s++];
            }
        }
        
        while(s <= m){
            ans[v[s].ss] += cnt;
            sub[idx++] = v[s++];
        }
        
        while(p <= e) sub[idx++] = v[p++];
        
        for(int i = 0;i < size;i++){
            v[i + idx1] = sub[i];
        }
    }
    void mergesort(vector<pair<int, int>> &v, int l, int r)
    {
            if(l>=r)
                return;
        
        int mid = (l+r)/2;
        mergesort(v,l,mid);
        mergesort(v,mid+1,r);
        merge(v,l,mid,r);
        
    }
    
    
    vector<int> countSmaller(vector<int>& nums) {
        int n  = nums.size();
        vector<pair<int,int>> v;
      
        for(int i = 0; i < n; i++)
        {
            v.push_back({nums[i], i});
        }
        ans.resize(n);
        mergesort(v,0, n-1);
        
        return ans;
    }
};