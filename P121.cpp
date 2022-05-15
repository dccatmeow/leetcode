/*You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[n][0] dp[n][1], first argument is position n
        // second argument, 1 is hold a stock, 0 is not hold a stock
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i=1 ; i<n; ++i){
            // not hold on stock in i-1 or hold on stock i-1 and sell it at i
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1] , -prices[i]);
        }
        return dp[n-1][0];
    }
};
