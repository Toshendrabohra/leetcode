class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         vector<vector<int>> ans;
     
        sort(nums.begin(),nums.end());
    ans.push_back(nums);
       int r=nums.size()-1;int l=r-1;
  while(l>=0)
  {
      while(l<r && nums[l]>=nums[r])
      {
          r--;
      }
      if(l<r)
      {
          swap(nums[l],nums[r]);
          sort(nums.begin()+l+1,nums.end());
          ans.push_back(nums);
          r=nums.size()-1;l=r-1;
      }
      else
      {
          l--;
          r=nums.size()-1;
      }
  }
        return ans;
    }
};