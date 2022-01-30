class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=n;
        int indx=0;
        while(cnt>0 && indx<n)
        {
            int start=indx;
            int cur=indx;
            int nxt=nums[start];
            do  
            {
                cur+=k;
                swap(nxt,nums[cur%n]);
               // cout<<(cur)%n<<" ";
                cnt--;
            }
            while(cnt>0 && cur%n!=start);
            indx++;
         cout<<endl;
        }
       
    }
};