class Solution
{
    public:
        bool canFinish(int n, vector<vector < int>> &prerequisites)
        {

            vector<vector < int>> graph(n);
            vector<int> indegree(n, 0);

            for (int i = 0; i < prerequisites.size(); i++)
            {
                graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
                indegree[prerequisites[i][0]]++;
            }

            queue<int> q;

            for (int i = 0; i < n; i++)
            {
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
            
            int cnt = 0;
            
            while(!q.empty())
            {
                int x = q.front();
                q.pop();
                cnt++;
                for ( auto i:graph[x])
                {
                    indegree[i]--;
                    if(indegree[i] == 0)
                        q.push(i);
                }
            }
            
            if(cnt == n)
                return true;
            return false;
        }
    
    
};