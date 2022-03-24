class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int cnt=0;
        int n=people.size();
        sort(people.begin(),people.end());
        int l=0,r=n-1;
        while(l<r)
        {
            if(people[l]+people[r]<=limit)
            {
                l++;
                r--;
                
            }
            else
                r--;
            cnt++;
        }
        if(l==r)
        {
            cnt++;
        }
        return cnt;
    }
};