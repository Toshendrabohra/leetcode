class Solution {
public:
    
        long long  int q,p;
      long long    int dp[101][101];
    long long   int uniquePaths(int m, int n) {
    p=m;
        q=n;
         for(int i=0;i<=100;i++)
            for(int j=0;j<=100;j++)dp[i][j]=-1;
          long long int x=cnt(0,0);
     return x;
        
    }
  
   
     long long  int cnt(int a,int b)
    {
        if(dp[a][b]!=-1)
            return dp[a][b];
       else  if(b==q-1 || a==p-1)
            dp[a][b]=1;
      else
          dp[a][b]=cnt(a,b+1)+cnt(a+1,b);
        return dp[a][b];
    }
};