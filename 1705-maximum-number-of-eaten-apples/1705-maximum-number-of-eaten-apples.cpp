class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int cur=0;
        priority_queue<pair<int,int>> p;
     
        int n=apples.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(apples[i]!=0)
            {
                p.push({-(days[i]+cur),apples[i]});
            }
            cur++;
            while(!p.empty() && -p.top().first<cur)
            {
                p.pop();
            }
            if(!p.empty()){
              pair<int,int> dum=p.top();
                p.pop();
              ans++;
                dum.second--;
                if(dum.second!=0)
                {
                    
                    p.push(dum);
                }
            }
            
        }
        while(!p.empty())
        {
           // cout<<p.top().first<<" "<<p.top().second;
            ans+=min(p.top().second,-p.top().first-cur);
            cur+=min(p.top().second,-p.top().first-cur);
            p.pop();
        }
        return ans;
    }
};