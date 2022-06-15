class Solution
{
    bool predecessor(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();

        if (abs(n - m) != 1)
            return false;

        if (n < m)
        {
            swap(s1, s2);
            swap(n, m);
        }

        int cnt = 0;
        int indx = 0;

        for (int i = 0; i < n; i++)
        {
            if (indx >= m || s2[indx] != s1[i])
            {
                cnt++;
            }
            else
                indx++;
        }
        // cout << s1 << " " << s2 << " "<< cnt<<endl;
        return cnt == 1;
    }

    void dfs(int cur, vector<vector < int>> &graph, vector< int > &depth)
    {
        depth[cur] = 1;

        for (auto &i: graph[cur])
        {
            if (depth[i] == -1)
                dfs(i, graph, depth);

            depth[cur] = max(depth[i] + 1, depth[cur]);
        }
    }

    public:
        int longestStrChain(vector<string> &word)
        {
            int n = word.size();
            vector<vector < int>> graph(n + 1);

            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (predecessor(word[i], word[j]))
                    {
                       // cout << i << " " << j<<endl;
                        string s1 = word[i], s2 = word[j];
                        if (s1.size() < s2.size())
                        {
                            graph[i].push_back(j);
                        }
                        else
                            graph[j].push_back(i);
                    }
                }
            }

            vector<int> depth(n + 1, -1);
            int ans = 0;

            for (int i = 0; i < n; i++)
            {
                if (depth[i] == -1)
                    dfs(i, graph, depth);
                ans = max(ans, depth[i]);
            }

            return ans;
        }
};