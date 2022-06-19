class Solution {
public:
    vector<vector<int>> trie {1, vector<int>(26,-1)};
    vector<vector<int>> dict {1,{1}};
    int node = 0;
    
    void insert(string &str , int x)
    {
        int n = str.size();
        int cnt = 0;
        for( int  i = 0; i < n; i++)
        {
            if(trie[cnt][str[i] - 'a'] == -1)
            {
                trie.push_back(vector<int>(26,-1));
                trie[cnt][str[i] - 'a'] = ++node;
               
                
            }
            
            cnt =  trie[cnt][str[i] - 'a'];
             if(dict.size() <=cnt)
             {
                 dict.push_back({x});
             }
             else  if(dict[cnt].size() < 3)
                dict[cnt].push_back(x);
        }
    }
    
    vector<vector<string>> find( string &str, vector<string> &prod)
    {
        vector<vector<string>> ans;
        int cnt = 0;
        for( int i = 0; i < str.size(); i++)
        {
            if(cnt != -1)
            cnt = trie[cnt][str[i] - 'a'];
            
            vector<string> dum;
            
            if(cnt != -1)
            {
                for ( auto &indx:dict[cnt])
                {
                    dum.push_back(prod[indx]);
                }
            }
            
                ans.push_back(dum);
        }
        
        return ans;
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        
        int n = products.size();
        for( int i = 0; i < n; i++)
        {
            insert(products[i], i);
        }
        
        return find(searchWord, products);
    }
};