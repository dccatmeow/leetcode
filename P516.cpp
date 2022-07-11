/*
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements 
without changing the order of the remaining elements.

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // dynamic programming
        // dp[i][j] is the size of longest palindromic substring
        // from s[i] to s[j]
        int n = s.size();
        if(n<2){
            return n;
        }
        vector<vector<int>> dp(n, vector<int>(n,0));
        for (int i=0; i<n;++i){
            // single letter is a palindromic substring
            dp[i][i] = 1;
        }
        // iterate from substring length=2 to n
        for (int len=2; len<=n; ++len){
            for(int i=0; i<=n-len; ++i){
                int j = i+len-1;
                if (s[i] == s[j]){
                    dp[i][j]=dp[i+1][j-1]+2;
                }else{
                    // remove i or remove j
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};
