//74. Search a 2D Matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int r = m*n;
        int l(0);
        while(l<=r){
            int mid = l+(r-l)/2;
            int x =mid/n;
            int y=mid%n;
            if (x<0 || y<0 || x>=m ||y>=n){
                return false;
            }
            if (matrix[x][y]<target){
                l = mid+1;
            }else if (matrix[x][y]>target){
                r = mid-1;
            }else{
                return true;
            }
        }
        return false;
        
    }
};
