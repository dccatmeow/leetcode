/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) 
with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //dp[prices.size()][0, 1]
        int n = prices.size();
        if (n<2){
            return 0;
        }
        int dp[n][2];
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[1][0] = max(dp[0][0], dp[0][1]+prices[1]);
        dp[1][1] = max(dp[0][1], -prices[1]);
        for(int i=2; i<n;++i){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-2][0]-prices[i]);
        }
        return dp[n-1][0];
    }
};
