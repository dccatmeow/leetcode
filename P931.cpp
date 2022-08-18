/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below 
or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), 
or (row + 1, col + 1).
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> mem(n, vector<int>(m, 10000));
        int tmp;
        for (int i=n-1; i>=0;--i){
            for (int j=0; j<m; ++j){
                if (i==n-1){
                    mem[i][j] = matrix[i][j];
                }else{
                    if (j==0){
                        tmp = min(mem[i+1][j], mem[i+1][j+1]);
                    }else if (j==m-1){
                        tmp = min(mem[i+1][j], mem[i+1][j-1]);
                    }else{
                        tmp = min(mem[i+1][j], mem[i+1][j-1]);
                        tmp = min(tmp, mem[i+1][j+1]);
                    }
                    mem[i][j] = min(mem[i][j], tmp+matrix[i][j]);
                }
            }
        }
        auto res = mem[0];
        sort(res.begin(), res.end());
        return res[0];
    }
};
