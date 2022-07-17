/*
Imagine you have a special keyboard with the following keys:

A: Print one 'A' on the screen.
Ctrl-A: Select the whole screen.
Ctrl-C: Copy selection to buffer.
Ctrl-V: Print buffer on screen appending it after what has already been printed.
Given an integer n, return the maximum number of 'A' you can print on the screen with at most n presses on the keys.

Example 1:

Input: n = 3
Output: 3
Explanation: We can at most get 3 A's on screen by pressing the following key sequence:
A, A, A
*/

class Solution {
public:
    int maxA(int n) {
        if (n<7){
            return n;
        }
        // dp[i] means the max number of 'A' it can get with i keys
        // besides A at beginning ctrl+A C V(VV, VVV, VVVV) are the way to get max 'A'
        // A C V  dp = 2*dp[i-3]
        // A C V V dp = 3*dp[i-4]
        // A C V V V dp = 4*dp[i-5]
        // A C V V V V dp = 5*dp[i-6]
        // A C V V V V V 6*dp[i-7] is not better than A C V A C V V 6*dp[i-7], so the result should be iterating in above 4
        vector<int> dp(n+1, 0);
        for (int i=0; i<7; ++i){
            dp[i] = i;
        }
        int tmp, tmp1;
        for (int i=7; i<=n; ++i){
            tmp = max(2*dp[i-3], 3*dp[i-4]);
            tmp1 = max(4*dp[i-5], 5*dp[i-6]);
            dp[i] = max(tmp, tmp1);
        }
        return dp[n];
    }
};
