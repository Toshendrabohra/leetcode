class Solution {
public:
    bool sumGame(string num) {
        int cnt=0;
        int l_vac=0;
        int r_vac=0;
        int l_sum=0;
        int r_sum=0;
        int n=num.size();
        for(int i=0;i<n;i++)
        {
            if(i<n/2)
            {
                if(num[i]=='?')
                    l_vac++;
                else
                    l_sum+=num[i]-'0';
            }
            else
            {
                 if(num[i]=='?')
                    r_vac++;
                else
                    r_sum+=num[i]-'0';
            }
        }
        cnt=l_vac+r_vac;
        if(cnt%2)
            return true;
        else
        {
           // int flag=0;
            int temp_l=l_sum+(l_vac/2)*9;
                if(l_vac%2)
                  temp_l+=9;
            int temp_r=r_sum;
            int diff=temp_l-temp_r;
            if(diff>=0 && diff>9*(r_vac-r_vac/2))
                return true;
            if(diff<0 && -diff>9*(l_vac/2))
                return true;
            temp_l=l_sum;
            temp_r=r_sum+9*(r_vac/2);
            diff=temp_l-temp_r;
            if(diff>=0 && diff>9*(r_vac-r_vac/2))
                return true;
            if(diff<0 && -diff>9*(l_vac/2))
                return true;
            return false;
        }
    }
};