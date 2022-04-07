class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        //bool poss=false;
        vector<vector<int>> graph(n+1);
        queue<int> q;
        set<int> s;
        
        for(int i=0;i<dislikes.size();i++)
        {
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        vector<int> colour(n+1,-1);
        for(int i=1;i<=n;i++)
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