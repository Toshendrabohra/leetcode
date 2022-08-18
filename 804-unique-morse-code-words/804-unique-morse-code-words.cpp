class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        map<string, int> m;
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        int ans = 0;
        for(int i = 0; i < words.size(); i++)
        {
            string dum ;
            for( int j = 0; j < words[i].size(); j++)
            {
                dum += morse[words[i][j] - 'a'];
            }
            if(m[dum] == 0)
                ans++;
            m[dum]++;
        }
        
        return ans;
    }
    
};