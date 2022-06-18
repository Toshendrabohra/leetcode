class WordFilter
{
    
    public:
        vector<vector<int>> trie{1, vector<int> (27, -1)};
   	    vector<vector<int>> nom{1, vector<int> (27, -1)};
    int node = 0;
  //  vector<string> dict;
    void insert(string &str, int &x, vector<string> &words)
    {
        int n = str.size();
        int cnt = 0;
         for (int j = 0; j < n; j++)
            {
                if(trie[cnt][str[j] - 'a'] == -1)
                {
                    trie.push_back( vector<int> (27, -1));
                    nom.push_back( vector<int> (27, -1));
                    trie[cnt][str[j] - 'a']  = ++node;
                    nom[cnt][str[j] - 'a']  = x;
                }
                else
                {
                    if( (int)words[nom[cnt][str[j] - 'a']].size() <n)
                        nom[cnt][str[j] - 'a']  = x;
                }
                
                cnt = trie[cnt][str[j] - 'a'];
            }
    }
    
    int find(string &str)
    {
        int cnt = 0;
        int ans = -1;
        int n = str.size();
        
         for (int j = 0; j < n; j++)
            {
             
                if(trie[cnt][str[j] - 'a'] == -1)
                {
                 
                   return -1;
                }
                
                ans = nom[cnt][str[j] - 'a'];
                cnt = trie[cnt][str[j] - 'a'];
               
            }

       // cout<<1;
        return ans;
        
    }
    
    WordFilter(vector<string> &words)
    {
        int n = words.size();
      
        for (int i = 0; i < n; i++) 
        {
            int m = words[i].size();
            string word;
            string suff = words[i];
            reverse(suff.begin(), suff.end());
            for ( int j = 0; j < m; j++)
            {
                word += words[i][j];
                
                string temp = word + "{" + suff;
                // cout<<temp<<endl;
                insert(temp, i, words);
               
            }
        }
    }
    
    int f(string prefix, string suffix) 
    {
       
        reverse(suffix.begin(), suffix.end());
        string word = prefix + "{" + suffix;
        return find(word);
        
    }
};

/**
 *Your WordFilter object will be instantiated and called as such:
 *WordFilter* obj = new WordFilter(words);
 *int param_1 = obj->f(prefix,suffix);
 */
