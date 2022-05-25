class Solution
{
    public:
        static bool comp(vector<int> &a, vector<int> &b)
        {
            if (a[0] != b[0])
                return a[0] < b[0];
            return a[1] > b[1];
        }
    int maxEnvelopes(vector<vector < int>> &envelopes)
    {
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> dp;
        dp.push_back(1e5);

        for (int i = 0; i < envelopes.size(); i++)
        {
            int x = lower_bound(dp.begin(), dp.end(), envelopes[i][1]) - dp.begin();

            if (x != dp.size())
                dp[x] = envelopes[i][1];
            else
                dp.push_back(envelopes[i][1]);
        }

        return dp.size();
    }
};