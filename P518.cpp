/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // i is 0,..i-1 in coins are used (it can be multiple uses)
        // j is the amount
        // dp[i][j] is how many combinations
        // there is no duplication because coin type is from 1 to n
        // amount is also from smallest to largest
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        for(int i=1; i<=n; ++i){
            // amount is zero, zero coin is needed, so only one solution
            dp[i][0] = 1;
            for(int j=1; j<=amount;++j){
                if (coins[i-1]>j){
                    // not use coin[i-1]
                    dp[i][j] = dp[i-1][j];
                }else{
                    // not use i-1 in coin (0,...i-2) + 
                    // use i-1 in coin, at least 1, same as j = j-coins[i-1]
                    dp[i][j] = dp[i-1][j]+ dp[i][j-coins[i-1]];
                }
            }
        }
        return dp[n][amount];
    }
};
