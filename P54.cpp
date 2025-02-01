/*
  54. Spiral Matrix
  Given an m x n matrix, return all elements of the matrix in spiral order.


*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i(0),p(0); //i,j row
        int j=matrix.size()-1; //p,q column
        int q = matrix[0].size()-1;
        vector<int> res;
        while(i<=j && p<=q){
            // row 0, column increase
            for (int e=p; e<=q;e++){
                res.push_back(matrix[i][e]);
            }
            i++;
            // column q, row increase
            for (int e=i; e<=j; e++){
                res.push_back(matrix[e][q]);
            }
            q--;
            if (i<=j){
                // row j, column decrease
                for (int e=q; e>=p; e--){
                    res.push_back(matrix[j][e]);
                }
                j--;
            }
            if (p<=q){
                // colum p, row decrease
                for (int e=j; e>=i; e--){
                    res.push_back(matrix[e][p]);
                }
                p++;
            }
        }
    return res;
        
    }
};
