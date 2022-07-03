class Solution
{
    public:
        int wigg(vector<int> &nums, int x, int prev)
        {
            int flag = 0;
            if (prev == -1)
                flag = 1;
            int cnt = 0;
            int n = nums.size(); 
            
            for (int i = 0; i < n; i++)
            {

                if (flag == 1)
                {
                    if (nums[i]>prev)
                    {
                        cnt++;
                        flag = 1-flag;
                        prev = nums[i];
                    }
                    else
                    {
                        prev = min(nums[i], prev);
                    }
                    
                }
                else
                {
                     if (nums[i]<prev)
                    {
                        cnt++;
                        flag = 1-flag;
                        prev = nums[i];
                    }
                    else
                    {
                        prev = max(nums[i], prev);
                    }
                }
            }
            
            return cnt;
        }

    int wiggleMaxLength(vector<int> &nums)
    {
        return max(wigg(nums, 0, -1), wigg(nums, 0, 1001));
    }
};