class Solution
{
    public:
        int minimumTotal(vector<vector < int>> &triangle)
        {
            int n = triangle.size();
            for (int i = 1; i < n; i++)
            {
                for (int j = 0; j < triangle[i].size(); j++)
                {
                    int mn;
                    if (j != i)
                        mn = triangle[i - 1][j];
                    else
                        mn = triangle[i - 1][j - 1];
                    if (j > 0)
                        mn = min(mn, triangle[i - 1][j - 1]);
                    triangle[i][j] += mn;
                }
            }
            return* min_element(triangle[n - 1].begin(), triangle[n - 1].end());
        }
};