/*
You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.
You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, 
and any egg dropped at or below floor f will not break.
Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. 
However, if the egg does not break, you may reuse it in future moves.
Return the minimum number of moves that you need to determine with certainty what the value of f is.

Example 1:

Input: k = 1, n = 2
Output: 2
Explanation: 
Drop the egg from floor 1. If it breaks, we know that f = 0.
Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
If it does not break, then we know f = 2.
Hence, we need at minimum 2 moves to determine with certainty what the value of f is.
*/

class Solution {
public:
    int superEggDrop(int k, int n) {
        // dp[i][j] stores the minimum steps needed to find out floor f in j floors
        // with i egg. Floor f is the last floor where egg will not break
        // initialize worst scenario is every floor need to drop an egg
        vector<vector<int>> dp(k+1, vector<int>(n+1, n));
        for (int j=1; j<=n; ++j){
            // one egg, every floor need to be tested
            dp[1][j] = j;
        }
        int l(0),r(0),m(0);
        for (int i=2; i<=k; ++i){
            // iterate from 2 egges to k eggs
            dp[i][1] = 1; // 1 floor always 1
            dp[i][0] = 0; // 0 floor no need to throw
            for (int j=2; j<=n; ++j){
                // iterate from 2 floors to n floors
                l = 2;
                r = j;
                int upper=0;// initialize upper and lower different
                int lower = 1;
                while(l<=r){
                    // use binary search
                    m = l+(r-l)/2;
                        // first throw at floor m
                        // if egg breaks it still need dp[i-1][m-1]
                        // if egg does not break it still need dp[i][j-m]
                        // dp[i][j] = min(dp[i][j], 1+max(dp[i-1][m-1], dp[i][j-m]) );
                    upper = dp[i][j-m]; // monotonically decreasing with m
                    lower = dp[i-1][m-1];// monotonically increasing with m 
                    if (upper == lower){
                        dp[i][j] = min(dp[i][j], 1+upper);
                        break;
                    }else if (upper>lower){
                        l = m+1;
                    }else if (upper<lower){
                        r = m-1;
                    }
                    dp[i][j] = min(dp[i][j], 1+max(upper, lower) );
                }
            }
        }
        return dp[k][n];
    }
};
