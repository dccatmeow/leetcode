/*
Given a m x n matrix mat and an integer k, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:

i - k <= r <= i + k,
j - k <= c <= j + k, and
(r, c) is a valid position in the matrix.
 

Example 1:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
Output: [[12,21,16],[27,45,33],[24,39,28]]
*/

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        // Dynamica programing
        //prefix sum dp[i][j] is sum from mat[0][0] to mat[i-1][j-1]
        // dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + mat[i-1][j-1];
        // dp[i+1][j+1] = dp[i+1][j]+dp[i][j+1] - dp[i][j] +mat[i][j];
        int m = mat.size();
        int n = mat[0].size();
        int top = 0, bottom=0, left=0, right=0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i<m; i++){
            for(int j =0; j<n; j++){
                dp[i+1][j+1] = dp[i+1][j] + dp[i][j+1] - dp[i][j] + mat[i][j];                
            }
        }
        // res[i][j] is [top, left] to [bottom, right]
        // dp[bottom+1][right+1] exclude rest area
        // res[i][j] = dp[bottom+1][right+1] - dp[top][right+1] - dp[bottom+1][left] +dp[top][left];
        for (int i = 0; i<m; i++){
            for(int j =0; j<n; j++){
                top = max(i-K, 0);
                left = max(j-K, 0);
                bottom = min(i+K, m-1);
                right = min(j+K, n-1);
                res[i][j] = dp[bottom+1][right+1] - dp[top][right+1] - dp[bottom+1][left] +dp[top][left];
            }
        }
        return res;
    }
};
