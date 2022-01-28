class Trie {
private : 
    vector<vector<int>> trie;
        int node=0;
        vector<int> hotnode;
public:
    Trie() {
        trie.clear();
        hotnode.clear();
        node=0;
        trie.push_back(vector<int>(26,-1));
        hotnode.push_back(0);
    }
    
    void insert(string word) {
        int n=word.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(trie[cnt][word[i]-'a']==-1)
            {
                trie.push_back(vector<int>(26,-1));
                hotnode.push_back(0);
                trie[cnt][word[i]-'a']=++node;
            }
            cnt=trie[cnt][word[i]-'a'];
        }
        hotnode[cnt]=1;
    }
    
    bool dfs(string &word,int &n,int pos,int node) {
        if(pos==n)
        {
            if(hotnode[node])
                return true;
            return false;
        }
        if(word[pos]!='.')
        {
            if(trie[node][word[pos]-'a']==-1)
                return false;
            else
                return dfs(word,n,pos+1,trie[node][word[pos]-'a']);
        }
        else
        {
            bool dum=false;
           for(int i=0;i<26;i++) 
           {
               if(trie[node][i]!=-1)
               dum|=dfs(word,n,pos+1,trie[node][i]);
           }
            return dum;
        }
        
     
    }
};

class WordDictionary {
public:
    Trie dict;
    WordDictionary() {
        dict=Trie();
    }
    
    void addWord(string word) {
        dict.insert(word);
    }
    
    bool search(string word) {
        int n=(int)word.size();
        return dict.dfs(word,n,0,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */