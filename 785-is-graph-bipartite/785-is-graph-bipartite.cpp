class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
       
        queue<int> q;
        //set<int> s;
        int n=graph.size();
       
        vector<int> colour(n+1,-1);
        for(int i=0;i<n;i++)
        {
            if(colour[i]!=-1)
                continue;
            q.push(i);
            colour[i]=1;
            
            while(!q.empty())
            {
                int cur=q.front();
                q.pop();
                
                for(auto &j:graph[cur])
                {
                    if(colour[j]==-1)
                    {
                        colour[j]=1-colour[cur];
                        q.push(j);
                    }
                    else if(colour[j]==colour[cur])
                    {
                        //cout<<j<<" "<<cur;
                        return false;
                    }
                }
                
            }
        }
        return true;
   
    }
};