struct prop
    {
        int attack,defence;
    };
class Solution {
    
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n=properties.size();
        sort(properties.begin(),properties.end());
        prop greatest,nxt_grt;
        greatest.attack=-1,greatest.defence=-1;
        nxt_grt.attack=-1,nxt_grt.defence=-1;
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {  
            if(nxt_grt.attack>properties[i][0])
            {
               
                greatest.attack=nxt_grt.attack;
                greatest.defence=nxt_grt.defence;
            }
            if(greatest.defence>properties[i][1] && greatest.attack>properties[i][0])
            {
                ans++;
            }
            else if(nxt_grt.defence<properties[i][1])
            {
                nxt_grt.defence=properties[i][1];
                nxt_grt.attack=properties[i][0];
            }
        }
        return ans;
    }
};