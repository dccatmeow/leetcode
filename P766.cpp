/*
766. Toeplitz Matrix

Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.

A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.
*/

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        // check top left half of matrix
        for(int delta=0; delta<max(m,n); ++delta){
            int prev=-1;
            for (int i=0; i<m; ++i){
                int j=i+delta;
                if (i<m && j<n){
                    if (prev == -1){
                        // initialize prev
                        prev = matrix[i][j];
                    }else{
                        if (matrix[i][j]!=prev){
                            return false;
                        }
                    }
                }
            }
        }
        // check bottom right half of matrix
        for(int delta=1; delta<max(m,n); ++delta){
            int prev=-1;
            for (int i=0; i<m; ++i){
                int j=i-delta;
                if (i>=0 && j>=0 && j<n){
                    if (prev == -1){
                        // initialize prev
                        prev = matrix[i][j];
                    }else{
                        if (matrix[i][j]!=prev){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
