class Solution {
public:
    
    void make_a_move(int &x,int &y,char dir,int &cur_dir,vector<int> &dx,vector<int> &dy)
    {
        if(dir=='G')
        {
            x+=dx[cur_dir];
            y+=dy[cur_dir];
        }
        else if(dir=='L')
        {
            cur_dir=(cur_dir+1)%4;
        }
        else
        {
            cur_dir=(cur_dir-1+4)%4;
        }
        return;
            
    }
    
    bool isRobotBounded(string instructions) {
        int cur_dir=0;
        int x=0;int y=0;
        vector<int> dx={0,1,0,-1};
        vector<int> dy={1,0,-1,0};
        int n=instructions.size();
        
       
        for(int i=0;i<4*n;i++)
        {
            make_a_move(x,y,instructions[i%n],cur_dir,dx,dy);
            if(x==0 && y==0 && cur_dir==0)
            {
                int cnt=0;
                for(int j=0;j<n;j++)
                {
                    if(instructions[(i+j+1)%n]==instructions[j])
                    {
                        cnt++;
                    }                    
                }
                if(cnt==n)
                    return true;   
            }
        }
        return false;
        
    }
};