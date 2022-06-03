class NumMatrix {
public:
    vector<vector<int>> mat;
    NumMatrix(vector<vector<int>>& matrix) {
       
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        mat.resize( n+1, vector<int> (m+1,0));
        
        for( int i = 1 ; i<=n ; i++)
        {
            for( int j = 1; j<=m ; j++)
            {
                mat[i][j]+=mat[i][j-1]+matrix[i-1][j-1];
            }
        }
        
        for( int i = 1 ; i<=n ; i++)
        {
            for( int j = 1; j<=m ; j++)
            {
                mat[i][j]+=mat[i-1][j];
            }
        }
        
        
                


    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int left = mat[row2+1][col1];
        int up = mat[row1][col2+1];
        
        int common = mat[row1][col1];
        
        int tot = mat[row2+1][col2+1];
        
        return tot - left - up + common;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */