class Solution
{
    public:
        bool hasAllCodes(string s, int k)
        {
            set<int> seta;
            int cur = 0;
            int standard = (1 << k) - 1;

            for (int i = 0; i < s.size() ; i++)
            {
                cur = (cur << 1) + s[i] - '0';

                if (i >= k - 1)
                {
                    cur = cur & standard;
                    seta.insert(cur);
                    // cout<< cur << " ";
                }
            }

            // for (auto &i: seta)
            //     cout << i << " ";

            if (seta.size() == (1 << k))
                return true;
            return false;
        }
};