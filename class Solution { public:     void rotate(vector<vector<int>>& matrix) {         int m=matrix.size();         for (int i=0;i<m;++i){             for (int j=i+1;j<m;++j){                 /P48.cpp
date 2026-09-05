//48. Rotate Image
//You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

//You have to rotate the image in-place,

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m=matrix.size();
        for (int i=0;i<m;++i){
            for (int j=i+1;j<m;++j){
                // transpose
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i=0;i<m;++i){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
