// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

    public:
 
    vector<vector<int> > findDistance(vector<vector<char> >& matrix, int n, int m) 
    { 
        // Your code goes here
           int dx[]={1,0,-1,0};
           int dy[]={0,1,0,-1};    
        vector<vector<int>> ans(n,vector<int> (m,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='B')
                {
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }
        while(!q.empty())
        {
            pair<int,int> dum=q.front();
            for(int i=0;i<4;i++)
            {
                int x=dum.first+dx[i];
                int y=dum.second+dy[i];
                if(x>=0 && x<n && y>=0 && y<m && ans[x][y]==-1 && matrix[x][y]!='B')
                {
                    if(matrix[x][y]!='W')
                    {
                        ans[x][y]=1+ans[dum.first][dum.second];
                        q.push({x,y});
                    }
                }
            }
            q.pop();
        }
        return ans;
    } 
};

// { Driver Code Starts.


int main()
{

    int t;
    cin >> t;
    while(t--)
    {
    	int M,N;
        cin>>M;
        cin>>N;

        vector<vector<char> > matrix(M);
        for(int i=0; i<M; ++i)
        {
            matrix[i].resize(N);
            for (int j = 0; j < N; ++j)
                cin>>matrix[i][j];
        }

        vector<vector<int> >result;
        Solution obj;
        result = obj.findDistance(matrix, M,N); 
        for(int i=0; i<M; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout<<result[i][j]<<" ";
            cout<<"\n";
        }
    }

    return 0;
}  // } Driver Code Ends