class Solution {
public:
    bool validMountainArray(vector<int>& a) {
        int n=a.size();
        if(n<=2)
            return false;
        int flag=0;
        for(int i=0;i<n-1;i++)
        {
            if(a[i]<a[i+1] && flag==0)
            {
                continue;
            }
            else if(i!=0 && a[i]>a[i+1])
            {
                flag=1;
            }
            else
                return false;
        }
        if(flag==1)
        return true;
        return false;
    }
};