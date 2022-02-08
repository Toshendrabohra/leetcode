class Solution {
public:
    int addDigits(int num) {
        int ans=0;
        while(1)
        {
        while(num)
        {
            ans=(ans+num%10);
            num/=10;
        }
            num=ans;
            if(ans<10)
                break;
            ans=0;
        }
        return ans;
    }
};