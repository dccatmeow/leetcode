/*Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
  */

class Solution {
public:
    int minDistance(string word1, string word2) {
        // dp[i][j] represent how many steps needed 
        // for word1[0,i-1] converted to word2[0,j-1]
        // dp[i][j] could be dp[i-1][j]+1, deletion
        // could be dp[i-1][j-1] +1, replace
        // could be dp[i][j-1] +1, insertion
        int m = word1.size();
        int n = word2.size();
        // dp[0][0] means zero element in both words
        vector<vector<int>> dp(m+1, vector<int>(n+1, m+n));
        // boundary conditions
        for (int i=0; i<=m; ++i){
            // delete all the element
            dp[i][0] = i;
        }
        for (int j=0; j<=n; ++j){
            // add up all the element
            dp[0][j] = j;
        }
        for (int i=1; i<=m; ++i){
            for (int j=1; j<=n; ++j){
                if (word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(dp[i-1][j]+1, dp[i-1][j-1]+1);
                    dp[i][j] = min(dp[i][j-1]+1, dp[i][j]);
                }
            }
        }
        return dp[m][n];
        
    }
};
