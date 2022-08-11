/*
Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, 
and each pile has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones. The total number of stones across all the piles is odd, 
so there are no ties.

Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones either 
from the beginning or from the end of the row. This continues until there are no more piles left, 
at which point the person with the most stones wins.

Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.

Example 1:

Input: piles = [5,3,4,5]
Output: true
*/

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // calculate presum of piles
        int n = piles.size();
        vector<int> sumV(n, 0);
        int tmp(0);
        for (int i=0; i<n; ++i){
            tmp += piles[i];
            sumV[i] = tmp;
        }
        // dp[i][j] is the max sum of selected stones from i to j
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // initial condition, i-i select itself
        for (int i=0; i<n; ++i){
            dp[i][i] = piles[i];
        }
        for (int i=0; i<n; ++i){
            for (int len=2; len<=n; ++len){
                int j = len-1+ i;
                if (j>n-1){
                    continue;
                }
                // Alice select i: Bob play optimal is dp[i+1][j]
                // Alice select j: Bob play optimal is dp[i][j-1]
                // dp[i][j] = sum of i to j - dp[i+1][j] or
                //            sum of i to j - dp[i][j-1]
                int tmp_sum = sumV[j] - sumV[i]+piles[i];
                dp[i][j] = max(tmp_sum-dp[i+1][j], tmp_sum-dp[i][j-1]);
            }
        }
        
        return dp[0][n-1]>0;
    }
};
