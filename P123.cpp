/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[n][0/1/2][0/1]
        // middle one is how many trades left
        int n=prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2,0)));
        dp[0][0][0] = 0;
        dp[0][1][1] = -prices[0];
        dp[0][0][1] = -prices[0];
        for (int i=1; i<n; ++i){
            for (int j=1; j>=0; --j){
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+prices[i]);
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j+1][0] - prices[i]);
            }
        }
        return dp[n-1][0][0];
    }
};
