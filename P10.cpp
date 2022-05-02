/*
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        // dp[i][j] represent first i element in s and first j element in p
        // if there is match, dp[i][j]=true;
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        // if p is empty dp[x][0] is always false
        // dp[0][x] is true if p is ".*n*", elements are cancelled
        for (int j=2; j<=p.size(); j=j+2){
            // start from second element in p
            if (p[j-1] == '*'){
                dp[0][j] = true;
            }else{
                break;
            }
        }
        for (int i=1; i<=m; ++i){
            for (int j=1; j<=n; ++j){
                if (p[j-1] == '.'){
                    dp[i][j] = dp[i-1][j-1];
                }else if (p[j-1] == '*'){
                    // * is zero times
                    if (dp[i][j-2]){
                        dp[i][j] = true;
                    }else if(p[j-2] == '.'){
                        // * is used at least one time
                        // .* represent s[i-1]
                        dp[i][j] = dp[i-1][j];
                    }else{
                        // p[j-2] is character
                        // a* at least used one time
                        // s[...ab] p[...ab*]
                        // s[....i] p[.....j]
                        // s[...a] p[...ab*]
                        // s[...i-1] p[.....j]
                        // there could be more a or more b, conservatively use dp[i-1][j]
                        if (s[i-1] == p[j-2]){
                            dp[i][j] = dp[i-1][j];
                        }else{
                            dp[i][j] = false;
                        }
                    }
                }else{
                    // p[j-1] is character
                    if (s[i-1] == p[j-1]){
                        dp[i][j] = dp[i-1][j-1];
                    }else{
                        dp[i][j] = false;
                    }
                }
            }
        }
        return dp[m][n];
    }
};
