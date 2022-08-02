class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> p;
        
        for( int i = 0; i < n; i++)
        {
            p.push({matrix[i][0],i,0});
        }
        
        int cnt = 1;
        
        while(cnt < k)
        {
            cnt++;
            vector<int> x = p.top();
            p.pop();
            if(x[2] < n-1)
                p.push({matrix[x[1]][x[2]+1], x[1], x[2]+1});
        }
        
        return p.top()[0];
    }
};