class Solution {
public:
    long long int logn(long long int n)
    {
        if(n==1)
            return 0;
        else if(n%2)
            return 1+min(logn(n+1), logn(n-1));
        return 1+logn(n/2);
    }
    int integerReplacement(int n) {
        return logn(n);
    }
};