/*
70. Climbing Stairs

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
class Solution {
public:
    int climbStairs(int n) {
        // dp
        // n=1, 1 dp[1]  
        // n=2, 2 dp[1]+dp[0], standing on 0 floor up 1 or up 2
        // n=3, 3 dp[2]+dp[1]
        // n=4, 5
        if (n==1) return 1;
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i=3;i<=n;++i){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
// time complexity O(n)
// space complexity O(n)
