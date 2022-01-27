class Trie
{
    public:
    vector<vector<int>> trie;
    vector<int> element;
    int nc;
    Trie()
    {
       
        trie.clear();trie.push_back(vector<int> (2,-1));
        element.clear();element.push_back(-1);
        nc=0;
    }
    void insert(int &val)
    {
        int cnt=0;
        for(int i=31;i>=0;i--)
        {
            int flag=((1<<i)&val)?1:0;
            if(trie[cnt][flag]==-1)
            {
                trie.push_back(vector<int> (2,-1));
                
                trie[cnt][flag]=++nc;
                
            }
            cnt=trie[cnt][flag];
        }
        
    }
    int find_max_xor(int &val)
    {
        int ans=0;
        int cnt=0;
         for(int i=31;i>=0;i--)
        {
            int flag=(((1<<i)&val)?1:0);
            if(trie[cnt][1-flag]!=-1)
            {
                ans+=(1<<i);
                cnt=trie[cnt][1-flag];
            }
            else
            {
                cnt=trie[cnt][flag];
            }
             
            
        }
        return ans;
    }
    
};
class Solution {
    
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        Trie tree;
        for(int i=0;i<n;i++)
        {
            tree.insert(nums[i]);
            ans=max(ans,tree.find_max_xor(nums[i]));
          
        }
        return ans;
    }
};