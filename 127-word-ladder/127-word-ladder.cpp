class Solution {
public:
    bool edge_poss(string &s1,string &s2)
    {
        int n=s1.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(s1[i]!=s2[i])
                cnt++;
        }
        return cnt==1;
    }
    int bfs(int &n,vector<vector<int>> &adj,int flag)
    {
        queue<int> q;
        q.push(n);
        vector<int> dis(n+1,0);
        while(!q.empty())
        {
            int x=q.front();
            if(x==flag)
                return dis[x];
            q.pop();
            for(auto &i:adj[x])
            {
                if(!dis[i])
                {
                    q.push(i);
                    dis[i]=dis[x]+1;
                }
            }
        }
        return -1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& word) {
        int n=word.size();
        vector<vector<int>> adj(n+1);
        int flag=-1;
        
        for(int i=0;i<n;i++)
        {
             if(edge_poss(beginWord,word[i]))
                {
                    adj[n].push_back(i);
                    adj[i].push_back(n);
                }
            if(word[i]==endWord)
                flag=i;
            for(int j=i+1;j<n;j++)
            {
                if(edge_poss(word[i],word[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        if(flag!=-1)
        return bfs(n,adj,flag)+1;
        return 0;
    }
    
};