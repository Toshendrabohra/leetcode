class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> hash(26,0);
        vector<int> hash_p(26,0);
        int m=p.size();
        int n=s.size();
        int no_of_char=0;
        for(int i=0;i<m;i++)
        {  if(!hash_p[p[i]-'a'])
            no_of_char++;
            hash_p[p[i]-'a']++;
          
        }
        vector<int> ans;
        int matching=0;
        for(int i=0;i<n;i++)
        {
            if(i>=m)
            {
                if(hash[s[i-m]-'a']==hash_p[s[i-m]-'a'])
                    matching--;
                hash[s[i-m]-'a']--;
            }
               hash[s[i]-'a']++;
            if(hash[s[i]-'a']==hash_p[s[i]-'a'])
                matching++;
            if(matching==no_of_char)
                ans.push_back(i-m+1);
            //cout<<matching<<" "<<endl;
        }
        return ans;
    }
};