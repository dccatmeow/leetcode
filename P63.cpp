/*
63. Unique Paths II

You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m= obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if (obstacleGrid[0][0]==1||obstacleGrid[m-1][n-1]==1){
            return 0;
        }
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        // dp[i+1][j+1] corresponding obstacleGrid[i][j]
        dp[1][0] =1;// this initialize dp[1][1] = 1;
        for (int i=0; i<m;++i){
            for (int j=0; j<n; ++j){
                if (obstacleGrid[i][j]==0){
                    dp[i+1][j+1] = dp[i][j+1]+dp[i+1][j];
                }
            }
        }
        return dp[m][n];
    }
};
