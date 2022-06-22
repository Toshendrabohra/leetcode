class Solution
{
    public:
        void quickselect ( int &l, int &r, int &pivot, vector<int> &nums, int &k)
        {
            int x = l + 1;
            
            for(int i = x; i <= r; i++)
            {
                if(nums[i] <= nums[l])
                {
                    swap(nums[i], nums[x++]);
                }
            }
            swap(nums[l], nums[x - 1]);
            
            if(x - l  == k)
            {
                k = 0;
                l = x - 1;
                r = l;
            }
            else if( x - l  > k)
            {
                r = x - 2;
            }
            else
            {
                k -= (x - l);
                l = x ;   
            }
        }
    
        int findKthLargest(vector<int> &nums, int k)
        {
            int n = nums.size();
            int l = 0, r = n - 1;
            k = n - k + 1;
            while(l < r)
            {
                int pivot = l;
                quickselect(l, r, pivot, nums, k);
              //  cout<<l<<" "<<r<<" "<<k<<endl;
            }
            
            return nums[l];
        }
};