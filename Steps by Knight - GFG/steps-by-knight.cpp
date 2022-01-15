// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    bool valid(int x,int y,int n)
    {
        if(x>0 && x<=n && y>0 && y<=n)
        return true;
        return false;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	   int vis[n+1][n+1];
	   memset(vis,0,sizeof(vis));
	   vis[KnightPos[0]][KnightPos[1]]=1;
	   queue<pair<int,int>> q;
	   int x[]={2,-2,0,0};
	   int y[]={0,0,-2,2};
	   int dx[]={-1,1};
	   q.push({KnightPos[0],KnightPos[1]});
	   while(!q.empty())
	   {
	       pair<int,int> dum=q.front();
	       if(dum.first==TargetPos[0] && dum.second==TargetPos[1])
	       break;
	       q.pop();
	       for(int i=0;i<4;i++)
	       {
	           for(int j=0;j<2;j++)
	           {
	               int xx=dum.first-x[i];
	               int yy=dum.second-y[i];
	               if(i<2)
	               yy+=dx[j];
	               else
	               xx+=dx[j];
	               if(valid(xx,yy,n) && !vis[xx][yy])
	               {
	                   q.push({xx,yy});
	                   vis[xx][yy]=1+vis[dum.first][dum.second];
	               }
	           }
	       }
	   }
	   return vis[TargetPos[0]][TargetPos[1]]-1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends