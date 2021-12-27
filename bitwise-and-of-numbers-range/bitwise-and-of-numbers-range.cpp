class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
     long long  int l=1,r=2;
       // cout<<left<<" "<<right<<endl;
        if(left==0)
            return 0;
        while(r<=left)
        {
            l=r;r*=2;
        }
        if(left>=l && right<r)
        {
            return l^rangeBitwiseAnd(left-l,right-l);
        }
        return 0;
    }
};