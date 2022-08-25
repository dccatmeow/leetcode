/*
Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.

A falling path with non-zero shifts is a choice of exactly one element from each row of grid such that no two elements chosen 
in adjacent rows are in the same column.

Example 1:
Input: arr = [[1,2,3],[4,5,6],[7,8,9]]
Output: 13
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m= grid.size();
        int n=grid[0].size();
        // at position m n the minimum sum of falling path
        auto dp = vector<vector<int>>(m, vector<int>(n, INT_MAX));
        for (int i=0; i<n; ++i){
            // first row is itself
            dp[0][i] = grid[0][i];
        }
        for (int i=1; i<m; ++i){
            // find the min and 2nd min in row i-1
            int min1(INT_MAX), min2(INT_MAX);
            for (auto k:dp[i-1]){
                if (k<=min1){
                    // most small
                    min2 = min1;
                    min1 = k;
                }else if (k<=min2){
                    // smaller than second smallest
                    min2 = k;
                }
            }
            for (int j=0; j<n; ++j){
                if (dp[i-1][j]!=min1){
                    dp[i][j] = min1 + grid[i][j];
                }else{
                    dp[i][j] = min2 + grid[i][j];
                }
            }
        }
        int res(dp[m-1][0]);
        // find min in last row
        for(auto i=1; i<n;++i){
            res = min(res, dp[m-1][i]);
        }
        return res;
    }
};
