class Solution {
public:
    int myAtoi(string s) {
      long long  int ans=0;
       long long int sign=1;
        int n=s.size();
        int flag=0;
        int x=0;
        //int int_mx=(1<<31)-1;
        
        while(s[x]==' '  && x<n)
        {
            x++;
        }
        for(int i=x;i<n;i++)
        {
            if(s[i]=='-' && i==x)
                sign=-1,flag=1;
            else if(s[i]=='+' && i==x)
                sign=1,flag=1;
            else if(s[i]>='0' && s[i]<='9')
            {
                ans=ans*10+s[i]-'0';
                if(ans*sign>=INT_MAX)
                {
                    return INT_MAX;
                }
                else if(ans*sign<=INT_MIN)
                    return INT_MIN;
             
            }
            else
                break;
        }
    
        if(sign<0)
            ans*=-1;
        return ans;
    }
};