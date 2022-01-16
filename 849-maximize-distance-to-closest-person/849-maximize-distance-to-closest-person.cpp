class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans=0;
        int cnt=0;
        int n=seats.size();
        int first=1;
        for(int i=0;i<n;i++)
        {
         if(seats[i]==0)   
             cnt++;
         else
         {
             if(first)
             {
                 ans=max(ans,cnt);
                 first=0;
             }
             else
                 ans=max(ans,(cnt+1)/2);
             cnt=0;
         }
        }
        ans=max(ans,cnt);
        return ans;
    }
};