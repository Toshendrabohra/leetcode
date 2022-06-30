class Solution
{
    public:
        int minMoves2(vector<int> &nums)
        {
            long long int sum = 0, psum = 0;
            sort(nums.begin(), nums.end());
            int x = nums[0];
            for (long long int i = 0; i < nums.size(); i++)
            {
                sum += nums[i]-x;
                nums[i] = nums[i] - x;
            }

            long long int ans = abs(sum), prev = 0;
            long long int n = nums.size();
            for (long long int i = 0; i < nums.size(); i++)
            {
                long long int diff = nums[i] - prev;
                long long int l = prev*i - psum, r = abs(sum - psum) - (n-i)*abs(nums[i]);
                long long int cost;
                if(i >= n - i)
                {
                    cost = diff*(n-i);
                }
                else
                    cost = diff*i ;
              //  cout<<l<<" "<<r<<" "<<cost<<endl;
                ans = min(ans, abs(l)+abs(r)+abs(cost));
                prev = nums[i];
                psum += nums[i];
            }
            
            return ans;
        }
};