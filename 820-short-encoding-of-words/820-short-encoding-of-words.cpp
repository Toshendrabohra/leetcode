class Solution
{
    public:
        vector<vector < int>> trie
        {
            1,
            vector<int> (26, -1)
        };
    vector<int> hotnode
    { 1,
        -1 };
    int node = 0;

    void insert(string & str)
    {
        int n = str.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (trie[cnt][str[i] - 'a'] == -1)
            {
                trie.push_back(vector<int> (26, -1));
                hotnode.push_back(-1);
                trie[cnt][str[i] - 'a'] = ++node;
            }

            hotnode[cnt] = 0;
            cnt = trie[cnt][str[i] - 'a'];
        }
        if(hotnode[cnt] == -1)
        hotnode[cnt] = 1;
    }

    int find(string & str)
    {

        int cnt = 0;
        for (int i = 0; i < str.size(); i++)
        {
            cnt = trie[cnt][str[i] - 'a'];
        }
            
        int x = hotnode[cnt];
        hotnode[cnt] = 0;
        return x;
    }
    int minimumLengthEncoding(vector<string> &words)
    {
        int ans = 0;

        for (int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            reverse(word.begin(), word.end());
            insert(word);
        }

        int cnt = 0;

        for (int i = 0; i < words.size(); i++)
        {

            string word = words[i];
            reverse(word.begin(), word.end());

            if (find(word))
            {
                cnt++;
                ans += words[i].size();
            }
        }

        return cnt + ans;
    }
};