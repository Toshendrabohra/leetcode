class Solution
{
    public:
        int removePalindromeSub(string s)
        {
            int cnt = 0;

            for (int i = 0; i < s.size() / 2; i++)
            {
                if (s[i] == s[s.size() - 1 - i])
                    cnt++;
            }

            if (cnt == s.size()/2)
                return 1;
            return 2;
        }
};