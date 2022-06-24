class Solution
{
    public:
        bool isPossible(vector<int> &target)
        {
            int n = target.size();
            
            if( n == 1 && target[0] == 1)
                return true;
            else if( n==1)
                return false;
            priority_queue<int> p;
            long long int sum = 0;

            for (int i = 0; i < target.size(); i++)
            {
                sum +=(long long int) target[i];
                p.push(target[i]);
            }
            
        
       

            while (2ll *p.top() >= sum )
            {
              //cout<<1<<" ";
                int x = p.top();
                p.pop();
                sum -= x;

                int rem = x % sum;

                if (rem == 0)
                    rem = sum;

                p.push(rem);
                sum += rem;

                if (rem == x)
                    break;
            }
            
            cout<<p.top();
            if(p.top() == 1)
                return true;
            return false;
        }
};