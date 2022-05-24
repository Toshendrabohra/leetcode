class Solution
{
    public:
        int longestValidParentheses(string s)
        {

            int last = -1;
            stack<int> open;
            int ans = 0;
            int n = s.size();
            vector<int> dp(n+1,0);
            
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '(')
                {
                    open.push(i);
                }
                else
                {
                    if (open.empty())
                    {
                        dp[i+1]=0;
                        continue;
                    }
                    else
                    {
                        dp[i+1]=i - open.top() + 1+ dp[open.top()];
                        ans = max(ans, dp[i+1]);
                        open.pop();
                    }
                }
            }
            
            return ans;
        }
};