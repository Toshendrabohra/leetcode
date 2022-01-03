class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n+1,0);
        vector<int> outdegree(n+1,0);
        for(int i=0;i<trust.size();i++)
        {
            indegree[trust[i][1]]++;
            outdegree[trust[i][0]]++;
        }
        int flag=0;int ans=-1;
        for(int i=1;i<=n;i++)
        {
            if(indegree[i]==n-1 && outdegree[i]==0 && ans==-1)
            {
                ans=i;
            }
            
        }
        return ans;
    }
};