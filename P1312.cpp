/*
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.
Example 1:

Input: s = "zzazz"
Output: 0
*/

class Solution {
public:
    int minInsertions(string s) {
        // dp[i][j] is the minimum steps to make s[i,j] palindrome
        int n=s.size();
        vector<vector<int>> dp(n,(vector<int>(n, n)));
        for (int i=0; i<n; ++i){
            // single character is a palindrome itself
            dp[i][i] = 0;
        }
        
        for (int len=2; len<=n; ++len){
            for (int i=0; i<n; ++i){
                int j = len+i-1;
                if (j>=n){
                    continue;
                }
                if(s[i] == s[j]){
                    if (len==2){
                        // "aa"
                        dp[i][j] = 0;
                    }else{
                        // "aba"
                        dp[i][j] = dp[i+1][j-1];
                    }
                }else{
                    // "abc"
                    dp[i][j] = min(dp[i+1][j],dp[i][j-1])+1;
                }
            }
        }
        return dp[0][n-1];
    }
};
