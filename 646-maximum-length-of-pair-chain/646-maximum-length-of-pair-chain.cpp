class Solution
{
    public:
        int findLongestChain(vector<vector < int>> &pairs)
        {
            
            int len = 1;
            sort(pairs.begin(), pairs.end());
            int prev = pairs[0][1];
            
            for (int i = 1; i < pairs.size(); i++)
            {
                if (pairs[i][0] > prev)
                {
                    prev = pairs[i][1];
                    len++;
                }
                else
                    prev = min(prev, pairs[i][1]);
            }

            return len;
        }
};