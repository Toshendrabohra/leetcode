class Solution {
public:
    int len(int x)
    {
        int cnt=0;
        while(x)
        {
            cnt++;
            x/=10;
        }
        return cnt;
    }
    int make(int len)
    {
        int x=0;
        int cnt=1;
        while(cnt<=len)
        x=10*(x)+cnt++;
        //cout<<x;
        return x;
    }
    int next(int &len,int x)
    {
        int ans=0;
        int cur=x%10-len+1;
        
        if(x%10==9)
        {
            return make(++len);
        }
        else
        {
            int dlen=len;
            while(dlen--)
            {
                ans=++cur+(ans)*10;
            }
            return ans;
        }
        
    }
    vector<int> sequentialDigits(int low, int high) {
        int le=len(low);
        int x=make(le);
        vector<int> ans;
        do
        {
            if(x>=low && x<=high)
            {
                ans.push_back(x);
            }
            x=next(le,x);
        }
        while(x<=high);
        return ans;
    }
};