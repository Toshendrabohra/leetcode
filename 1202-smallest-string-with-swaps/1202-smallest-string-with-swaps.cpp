class Solution {
public:
    vector<int> parent,size;
    int find_parent(int a)
    {
        if(parent[a]==a)
            return a;
        return parent[a]=find_parent(parent[a]);
    }
    void make_pair(int a,int b)
    {
        a=find_parent(a);
        b=find_parent(b);
        if(a!=b)
        {
            if(size[a]<size[b])
                swap(size[a],size[b]);
            size[a]+=size[b];
            parent[b]=parent[a];
        }
        
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        
        parent.clear();
        
        for(int i=0;i<n;i++)
            parent.push_back(i);
        
        size.clear();
        size.resize(n+1,1);
        
        for(int i=0;i<pairs.size();i++)
        {
            
            make_pair(pairs[i][0],pairs[i][1]);
        }
        
        vector<string> ans(n+1);
        for(int i=0;i<n;i++)
        {
            ans[find_parent(i)].push_back(s[i]);
        }
        
       
        for(int i=0;i<n;i++)
            if(!ans[i].empty())
            sort(ans[i].begin(),ans[i].end());
         
        string final_string;
        for( int i=n-1;i>=0;i--)
        {
            final_string+=ans[find_parent(i)].back();
            ans[find_parent(i)].pop_back();
        }
        
        reverse(final_string.begin(),final_string.end());
        return final_string;
        
        
    }
};