class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string,int> red_flags;
        for(int i=0;i<deadends.size();i++)
        {
            red_flags[deadends[i]]=1;
        }
        queue<string> q;
        if(red_flags["0000"]==1)
            return -1;
        if(target=="0000")
            return 0;
        q.push("0000");
        unordered_map<string ,int> dis;
        while(!q.empty())
        {
            string cur=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                string forward=cur,backward=cur;
                forward[i]=(forward[i]+1-'0')%10+'0';
                backward[i]=(backward[i]+9-'0')%10+'0';
                if(forward==target || backward==target)
                    return dis[cur]+1;
                if(red_flags.find(forward)==red_flags.end() 
                   && dis.find(forward)==dis.end())
                {
                    q.push(forward);
                    dis[forward]=dis[cur]+1;
                }
                if(red_flags.find(backward)==red_flags.end() 
                   && dis.find(backward)==dis.end())
                {
                    q.push(backward);
                    dis[backward]=dis[cur]+1;
                }
            }
        }
        return -1;
        
    }
};