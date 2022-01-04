class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)
            return 1;
        int dum=0;
        int cur=0;
        while((1<<cur)<=n)
        {
            dum+=(1<<cur);
            cur++;
        }
        return (n^dum);
    }
};