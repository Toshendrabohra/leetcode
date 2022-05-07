class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int end = INT_MIN;
        stack<int> s;

        for(int i = n - 1;i>=0;i--){
            if(end > nums[i]) return true;
            while(!s.empty() and nums[i] > s.top()){
                end = s.top();
                s.pop();
            }

            s.push(nums[i]);
        }

        return false;
    }
};