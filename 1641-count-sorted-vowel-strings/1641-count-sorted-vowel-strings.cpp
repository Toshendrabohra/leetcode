class Solution {
public:
    int count(int curPos , int &n , int vowel, vector<vector<int>> &dp)
    {
        if(curPos == n)
            return 1;
        
        if(dp[curPos][vowel] != -1)
            return dp[curPos][vowel];
        
        dp[curPos][vowel]=0;
        
        for( int i = vowel ; i < 5 ; i++)
        {
            dp[curPos][vowel]+=count ( curPos+1 , n , i , dp);
        }
        
        return dp[curPos][vowel];
    }
    int countVowelStrings(int n) {
        vector<vector<int>> dp (n+1, vector<int> (5,-1));
        map<char,int> hash;
        vector<char> vowels = {'a' , 'e' , 'i' , 'o' , 'u'};
        
        for(int i = 0 ; i < 5 ; i++)
            hash[vowels[i]] = i;
        
        return count(0 , n , 0 , dp);
        
    }
};