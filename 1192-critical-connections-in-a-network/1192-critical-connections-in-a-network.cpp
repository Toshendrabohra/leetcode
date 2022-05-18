class Solution {
public:
     vector<vector<int>> ans;
    void dfs(int node,int parent,vector<int> &disc,vector<int> &low,vector<int> g[]){
        static int time = 0;
        disc[node] = low[node] = time++;

        for(auto i:g[node]){
            if(i == parent) continue;
            if(disc[i] == -1){
                dfs(i,node,disc,low,g);
                low[node] = min(low[node],low[i]); 

                if(low[i] > disc[node]) ans.push_back({node,i});
            }
            else low[node] = min(low[node],disc[i]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> g[n], disc(n,-1), low(n,-1);

        for(auto i:connections){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }

        dfs(1,-1,disc,low,g);
        return ans;
    }
};