class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<string,char> m;
        map<char,string> hash;
        int n=s.size();
        int indx=0;
        int len_pat=pattern.size();
        for(int i=0;i<n;i++)
        {
            string temp;
            while(i<n && s[i]!=' ')
                temp+=s[i++];
            if(indx>=len_pat)
                return false;
            if(m.find(temp)==m.end())
            {
                if(hash.find(pattern[indx])!=hash.end())
                    return false;
                hash[pattern[indx]]=temp;
                m[temp]=pattern[indx++];
                
            }
            else
            {
               if(m[temp]!=pattern[indx]) 
                   return false;
                indx++;
            }

        }
        if(len_pat!=indx)
            return false;
        return true;
    }
};