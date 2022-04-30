class Solution {
public:
    double dfs(int cur, int end, int par , vector<vector<vector<double>>> &graph , int &prod , vector<double> &vis , vector<int> &loop)
    {
        int  flag=0;
        
        if(cur== end)
            return 1;
        
        loop[cur]=1;
        for(auto j:graph[cur])
        {
            int i=j[0];
            double x=0;
            if(i!=par && loop[i]!=1)
            {
                if(vis[i]==0)
                x = dfs(i, end, cur, graph, prod, vis ,loop);
                else
                x=vis[i];
            }
            if(!prod)
                return 1;
            if(x!=0 && x!=-1)
            {
                if(flag==1)
                {
                    if(vis[cur]!=x*j[1])
                    {                
                    prod = 0; return 1;
                    }
                }
                
                flag=1;
                vis[cur]=x*j[1];
            }
        }
        loop[cur]=2;
        
        if(flag==0)
            vis[cur]=-1;
    return vis[cur];
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        map<string, double> indexing;
        vector<double> finalAns;
        
        int cnt=1;
        for (int i = 0; i < equations.size() ; i++)
        {
            if(indexing[equations[i][0]] == 0)    
            {
                indexing[equations[i][0]] = cnt++;
            }
            if(indexing[equations[i][1]] == 0)
            {
                indexing[equations[i][1]] = cnt++;
            }
        }
        
        vector<vector<vector<double>>> graph (cnt);
        for (int i = 0; i < equations.size() ; i++)
        {
            graph[(int)indexing[equations[i][0]]].push_back({indexing[equations[i][1]],values[i]});
            graph[(int)indexing[equations[i][1]]].push_back({indexing[equations[i][0]],1.0/values[i]});
        }
        
        for( int i = 0; i < queries.size() ; i++)
        {
          
            vector<double> vis(cnt, 0);
            vector<int> loop(cnt, 0);
            double value;
            
          int prod=1;  
            if((int)indexing[queries[i][0]]!=0 && (int)indexing[queries[i][1]]!=0)
             value = (dfs((int)indexing[queries[i][0]] , (int)indexing[queries[i][1]] , -1 , graph  , prod, vis, loop));
                                                               else 
                                                               prod=0;
            
            if(prod)
                finalAns.push_back(value);
            else
                finalAns.push_back(-1.00);
            
        }
        return finalAns;
    }
};