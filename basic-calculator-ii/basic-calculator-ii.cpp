class Solution {
public:
    int make_oper(int a,int b,char op)
    {//cout<<a<<" "<<b<<endl;
        if(op=='*')
            return a*b;
        else
            return a/b;
    }
    int calculate(string s) {
        vector<char> ope={ '/','*','+' ,'-'};
        stack<int> tracker;
       long long int cur=0;
        char op='.';
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')continue;
             if(op!='.' && cur!=0)
            {
                if(op=='*' || op=='/')
                {
                cur=make_oper(tracker.top(),cur,op);
                    tracker.pop();
                }
                else if(op=='-')
                    {
                        cur*=-1;
                    }
                 //  tracker.push(cur);cur=0;
            op='.';
            }
            
            
            if(s[i]-'0'>=0 && s[i]-'0'<=9)
            {
             while(i<n && s[i]-'0'>=0 && s[i]-'0'<=9)
                cur=10*cur+s[i++]-'0';
                
            i--;
            }
         else if(s[i]==ope[1] || s[i]==ope[3] || s[i]==ope[2] || s[i]==ope[0])
            {
                op=s[i];
                tracker.push(cur);cur=0;
              //  i++;
            }
        }
          if(op!='.' && cur!=0)
            {
                if(op=='*' || op=='/')
                {
                cur=make_oper(tracker.top(),cur,op);
                    tracker.pop();
                }
                else if(op=='-')
                    {
                        cur*=-1;
                    }
                   tracker.push(cur);cur=0;
            op='.';
            }
        int ans=cur;
        while(!tracker.empty())
        {
            ans+=tracker.top();tracker.pop();
        }
        
    return ans;
    }
};