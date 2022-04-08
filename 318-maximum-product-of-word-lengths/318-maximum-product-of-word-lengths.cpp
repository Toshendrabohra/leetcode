class Solution {
public:
    int hash_fun(string word)
    {
        int n=word.size();
        vector<int> avl(26,0);
        
        for(int i=0;i<n;i++)
        {
            avl[word[i]-'a']=1;
        }
        
        int hash=0;
        for(int i=0;i<26;i++)
        {
            if(avl[i])
                hash=(hash|1ll<<i);
        }
        return hash;
    }
    int maxProduct(vector<string>& words) {
        
        int n=words.size();
        vector<int> hash(n);
        for(int i=0;i<n;i++)
        {
            hash[i]=hash_fun(words[i]);
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if((hash[i]&hash[j])==0)
                ans=max(ans,int(words[i].size()*words[j].size()));
            }
        }
        
        return ans;
    }
};