class Solution
{
    public:
     
    int maxEvents(vector<vector < int>> &events)
    {
        int ans = 0;
        int last = 0;

        sort(events.begin(), events.end());

        int i = 0;
        int n = events.size();
        priority_queue<int, vector<int>, greater<int>> p;
        
        while (i < n || !p.empty())
        {
            while( i < n && last >= events[i][0])
            {
                p.push(events[i++][1]);
            }
            while (!p.empty() && p.top()<last)
                p.pop();
            
            if(!p.empty())
            {
                p.pop();
                ans++;
            }
            
            last++;  
        }
            return ans;
    }
};