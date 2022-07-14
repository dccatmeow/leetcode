/*
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.
Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        //dp[i][j] is the minimum steps needed to make word1 and word2 the same
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        // word2 is empty
        for(int i=0; i<=m;++i){
            dp[i][0] = i;
        }
        // word1 is empty
        for (int j=0; j<=n; ++j){
            dp[0][j] = j;
        }
        // dp[i][j] is the word1 [0,i-1], word2 [0, j-1]
        for (int i=1; i<=m;++i){
            for (int j=1; j<=n; ++j){
                if (word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    // delete i or j with the minimum from either dp
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1])+1;
                }
            }
        }
        return dp[m][n];
    }
};
