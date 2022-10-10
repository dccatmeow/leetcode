/*
Given an m x n binary matrix mat, return the length of the longest line of consecutive one in the matrix.

The line could be horizontal, vertical, diagonal, or anti-diagonal.

Example 1:

Input: mat = [[0,1,1,0],[0,1,1,0],[0,0,0,1]]
Output: 3
*/

class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int m= mat.size();
        int n=mat[0].size();
        int res(0);
        int tmp(0);
        // dp[i][j][direction],
        // direction up, left, up left, up right. end with (i,j)
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n, vector<int>(4,0)));
        // add dummy row as boundary condition
        for (int i=1; i<=m; ++i){
            for (int j=0; j<n; ++j){
                if (mat[i-1][j]==1){
                    // up
                    if (dp[i-1][j][0] >0){
                        dp[i][j][0] = dp[i-1][j][0]+1;
                    }else{
                        dp[i][j][0] = 1;
                    }
                    // left
                    if (j-1>=0 && dp[i][j-1][1]>0){
                        dp[i][j][1] = dp[i][j-1][1]+1;
                    }else{
                        dp[i][j][1] = 1;
                    }
                    // left up
                    if (j-1>=0 && dp[i-1][j-1][2]>0){
                        dp[i][j][2] = dp[i-1][j-1][2]+1;
                    }else{
                        dp[i][j][2] =1;
                    }
                    // right up
                    if (j+1<n && dp[i-1][j+1][3]>0){
                        dp[i][j][3] = dp[i-1][j+1][3]+1;
                    }else{
                        dp[i][j][3]=1;
                    }
                }
                tmp = max(dp[i][j][0], dp[i][j][1]);
                tmp = max(tmp, dp[i][j][2]);
                tmp = max(tmp, dp[i][j][3]);
                res = max(res, tmp);
            }
        }
        return res;
    }
};
