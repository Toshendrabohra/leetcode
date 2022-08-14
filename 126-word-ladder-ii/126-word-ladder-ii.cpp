class Solution {
public:
       bool isValid(string s, string t){
        int x = 0;
        for(int i = 0;i < s.length();i++){
            if(s[i] != t[i]) x++;
        }
        
        return x == 1;
    }
    
    void bfs(int s, int e, int n, vector<int> g[], vector<int> parent[]){
        queue<int> q;
        vector<int> dist(n, 10000);
        
        q.push(s);
        dist[s] = 0;
        parent[s] = {-1};
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto i: g[node]){
                if(dist[i] > dist[node] + 1){
                    dist[i] = dist[node] + 1;
                    
                    q.push(i);
                    parent[i].clear();
                    parent[i].push_back(node);
                }
                else if(dist[i] == dist[node] + 1) parent[i].push_back(node);
            }
        }
    }
    
    void generatePaths(int node, vector<int> parent[], vector<int> &path, vector<vector<int>> &paths){
        if(node == -1) paths.push_back(path);
        else {
            path.push_back(node);
            
            for(auto i: parent[node]){
                generatePaths(i, parent, path, paths);
            }
            
            path.pop_back();
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int s = -1, e = -1, n = wordList.size();
        vector<vector<string>> ans;
        
        for(int i = 0;i < n;i++){
            if(wordList[i] == beginWord) s = i;
            if(wordList[i] == endWord) e = i;
        }
        
        if(e == -1) return ans;
        if(s == -1){
            wordList.push_back(beginWord);
            s = n;
            n++;
        }
        
        vector<int> g[n], parent[n], path;
        vector<vector<int>> paths;
        
        for(int i = 0;i < n;i++){
            for(int j = i + 1;j < n;j++){
                if(isValid(wordList[i], wordList[j])){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        
        bfs(s, e, n, g, parent);
        generatePaths(e, parent, path, paths);
        
        for(auto p: paths){
            vector<string> part;
            int np = p.size();
            for(int i = np - 1;i >= 0;i--){
                part.push_back(wordList[p[i]]);
            }
            
            ans.push_back(part);
        }
        
        return ans;
    }
};