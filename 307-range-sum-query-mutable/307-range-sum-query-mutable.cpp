class NumArray {
public:
    vector<int> seg;
    vector<int> arr;
    int n;
    void build(vector<int> &seg, vector<int> &arr, int s, int e, int indx)
    {
        if(e<s)
            return;
        else if(s == e)    
        {
            seg[indx] = arr[s];
            return;
        }
     //   cout<<s<<" "<<e<<endl;
        int mid = (s+e)/2;
        build(seg, arr, s, mid, 2*indx);
        build(seg, arr, mid+1, e, 2*indx+1);
        seg[indx] = seg[2*indx] + seg[2*indx+1];
    }
    
    void update_seg(vector<int> &seg, vector<int> &arr, int s, int e, int indx, int index, int val)
    {
        if(s == e)
        {
            seg[indx] = val;
            arr[s] = val;
            return;
        }
        
        int mid = (s+e)/2;
        if(index<= mid)
            update_seg(seg, arr, s, mid , 2*indx, index, val);
        else
            update_seg(seg, arr, mid+1, e, 2*indx + 1, index, val);
        seg[indx] = seg[2*indx] + seg[2*indx+1];
    }
    
    int query(vector<int> &seg, vector<int> &arr, int s, int e, int indx, int l, int r)
    {
        if(s > r || e < l)
            return 0;
        if(s>=l && e<=r)
            return seg[indx];
        
        int mid = (s+e)/2;
      int sl =   query(seg, arr, s,mid,2*indx, l,r);
      int rl =   query(seg, arr, mid+1, e,2*indx+1, l, r);
        return sl + rl;
    }
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        arr.clear();
        seg.clear();
        seg.resize(4*n);
        arr = nums;
        build(seg, arr, 0, n-1, 1);
    }
    
    void update(int index, int val) {
        update_seg(seg, arr, 0, n-1, 1, index, val);
       // cout<<arr[index]<<" ";
    }
    
    int sumRange(int left, int right) {
        return query(seg, arr, 0, n-1, 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */