class Solution
{
    public:
        vector<vector < string>> ans;
        vector<string> temp;
    void n_queens(int cur, int &n, vector<int> &used, vector<int> &cord, vector<int> &back, vector<int> &forw)
    {
        if (cur == n)
        {
            vector<string> dum = temp;

            for (int i = 0; i < n; i++)
            {
                dum[i][cord[i]] = 'Q';
            }
            ans.push_back(dum);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (used[i] == 0 && back[cur - i + n] == 0 && forw[cur + i] == 0)
            {
                used[i] = 1;
                cord.push_back(i);
                back[cur - i + n] = 1 ;
                forw[cur + i]  = 1;
                n_queens(cur + 1, n, used , cord, back, forw);
                back[cur - i + n] = 0 ;
                forw[cur + i]  = 0;
                cord.pop_back();
                used[i] = 0;
            }
        }
    }

    vector<vector < string>> solveNQueens(int n)
    {
        string dummy;
        for (int i = 0; i < n; i++)
            dummy += '.';
        for (int i = 0; i < n; i++)
        {
            temp.push_back(dummy);
        }
        vector<int> used(n + 1, 0);
        vector<int> back(2*n+1, 0), forw(2*n+1, 0);
        vector<int> cord;
        n_queens(0, n, used, cord, back, forw);
        
        return ans;
    }
};