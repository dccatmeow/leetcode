/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
  
General idea is dynamic programing, set correct state, correct relationship to deduct n from n-1
  
  */
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n<2){
            return 0;
        }
        if (k == 0){
            return 0;
        }
        // [n][# of transaction][hold stock is 1]
        int dp[n][k+1][2];
        for (int m = k; m>=0; --m){
            dp[0][m][0] = 0;
            dp[0][m][1] = -prices[0];
        }
        
        for (int i=1; i<n;++i){
            dp[i-1][k][0] = 0;
            for (int j = k;j>0;--j){
                dp[i][j-1][0] = max(dp[i-1][j-1][0], dp[i-1][j-1][1]+prices[i]);
                dp[i][j-1][1] = max(dp[i-1][j-1][1], dp[i-1][j][0] - prices[i]);
            }
        }
        
        return dp[n-1][0][0];
    }
};
// time complexity O(n*k)
// space complexity O(n*k+1*2)
