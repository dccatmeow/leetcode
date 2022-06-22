/*
Given a 2D matrix matrix, handle multiple queries of the following type:

Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
*/

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        sumM.resize(n,vector<int>(m,0));
        sumM[0][0] = matrix[0][0];
        for (int j=1; j<m; ++j){
            // calculate i=0 case
            sumM[0][j] = sumM[0][j-1]+matrix[0][j];
        }
        // cacluate all other i cases
        for (int i=1; i<n; ++i){
            // calculate j=0 case
            sumM[i][0] = sumM[i-1][0]+matrix[i][0];
            // loop through all other j cases
            for (int j=1; j<m; ++j){
                sumM[i][j] = sumM[i][j-1]+sumM[i-1][j]-sumM[i-1][j-1]+matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0 && col1 ==0){
            return sumM[row2][col2];
        }else if (col1 == 0){
            return sumM[row2][col2] - sumM[row1-1][col2];
        }else if (row1 == 0){
            return sumM[row2][col2] - sumM[row2][col1-1];
        }
        return sumM[row2][col2] - sumM[row2][col1-1] - sumM[row1-1][col2] +sumM[row1-1][col1-1];
    }
private:
    vector<vector<int>> sumM;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
