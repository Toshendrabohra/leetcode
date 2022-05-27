class Solution
{
    public:
        bool increasingTriplet(vector<int> &nums)
        {

            vector<int> x;
            x = {nums[0], INT_MIN};

            for (int i = 1; i < nums.size(); i++) {
                if (x[0] >= x[1])
                {
                    if (x[0] < nums[i])
                        x[1] = nums[i];
                    else
                        x[0] = min(x[0], nums[i]);
                }
                else if (nums[i] > x[1])
                    return true;
                else if( nums[i]<= x[0])
                {
                    x[0]=nums[i];
                }
                else
                    x[1]=nums[i];
            }
            
            return false;
        }
};