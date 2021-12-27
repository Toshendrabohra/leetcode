class Solution {
public:
    int findComplement(int num) {
      //  num=INT_MAX;
       // cout<<num;
        long long int x=1;
        while(x<=num)
        {
            x*=2ll;
        }
        x--;
        return (x^num);
    }
};