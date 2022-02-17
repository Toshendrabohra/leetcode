class Solution {
public:
     void generate(vector<int>& nums,vector<vector<int>> &ans, int x,vector<int> prevlist ,int target)
    {
          if(target==0)
         {
              ans.push_back(prevlist);
         }
       else if(x==nums.size() || target<0)
        {//cout<<target<<" "<<x<<endl;
            return;
        }
       
        else
        {//unordered_map<int,int> m;
              // generate(nums,ans,x+1,prevlist,sum,target);
           while(target>=0)
            {
               
                
                  //  ans.push_back(prevlist);
                    generate(nums,ans,x+1,prevlist,target);
                target-=nums[x];
                    prevlist.push_back(nums[x]);
                   // prevlist.pop_back();
                 
                
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

                    vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        vector<int> prevlist;
       // ans.push_back(prevlist);
        generate(candidates,ans,0,prevlist,target);
        return ans;                                                                     
                                                                                        
                                                                                        
        
    }
};