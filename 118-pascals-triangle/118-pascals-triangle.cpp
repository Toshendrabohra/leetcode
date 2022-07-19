class Solution {
public:
    vector<vector<int>> generate(int n) {
         vector<vector<int>> trngl;
        trngl.push_back({1});
        if(n>1)
          trngl.push_back({1,1});
        if(n>2)
        for(int i=2;i<n;i++)
        {
            vector<int > dum;
            dum.push_back(1);
            for(int j=0;j<i-1;j++)
            {
                dum.push_back(trngl[i-1][j]+trngl[i-1][j+1]);
            }
             dum.push_back(1);
            trngl.push_back(dum);
        }
        return trngl;
    }
};