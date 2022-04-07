class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n+1,0),ans;
        for(int i=0;i<edges.size();i++)
        {
            //outdegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                ans.push_back(i);
        }
        return ans;
    }
};