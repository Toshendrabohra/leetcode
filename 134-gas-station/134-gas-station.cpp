class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tot_gas=0,tot_cost=0;
        int start=0;
        int cur=0;
        int n=gas.size();
        for(int i=0;i<n;i++)
        {
            tot_gas+=gas[i];
            tot_cost+=cost[i];
            cur+=gas[i]-cost[i];
            if(cur<0)
            {
                start=i+1;
                cur=0;
            }
        }
        if(tot_gas-tot_cost<0)
            return -1;
        return start;
            
    }
};