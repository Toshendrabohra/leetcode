class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        for(int i=0; i < (1<<9) ; i++)
        {
            int sum=0;
            int mask=i;
            int val=1;
            int count=0;
            vector<int> comb;
            while(mask)
            {
                if(mask%2)
                    sum+=val,count++,comb.push_back(val);
                mask/=2;
                val++;
            }
            
            if(count == k && sum == n)
            {
                ans.push_back(comb);
            }
            
        }
        
        return ans;
    }
};