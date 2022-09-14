/*
An attendance record for a student can be represented as a string where each character signifies whether the student was absent, 
late, or present on that day. The record only contains the following three characters:

'A': Absent.
'L': Late.
'P': Present.
Any student is eligible for an attendance award if they meet both of the following criteria:

The student was absent ('A') for strictly fewer than 2 days total.
The student was never late ('L') for 3 or more consecutive days.
Given an integer n, return the number of possible attendance records of length n that make a student eligible for an attendance award. 
The answer may be very large, so return it modulo 109 + 7.

Example 1:

Input: n = 2
Output: 8
*/
class Solution {
public:
    int checkRecord(int n) {
        //               k        k+1
        // end A         a0        b+d+f
        // end P no A    b1        b+d+f
        // end P w A     c2        a+c+e+g
        // end L no A    d3        b
        // end L w A     e4        a+c
        // end LL no A   f5        d
        // end LL w A    g6        e
        long long base = 1000000007;
        long long dp[7] = {1,1,0,1,0,0,0}; 
        long long next[7];
        for (int i=2; i<=n; ++i){
            next[0] = (dp[1]+dp[3]+dp[5])%base;
            next[1] = (dp[1]+dp[3]+dp[5])%base;
            next[2] = (dp[0]+dp[2]+dp[4]+dp[6])%base;
            next[3] = dp[1];
            next[4] = (dp[0]+dp[2])%base;
            next[5] = dp[3];
            next[6] = dp[4];
            memcpy(dp, next, sizeof(next));
        }
        long long res = 0;
        for (int i=0;i<7;++i){
            res = (res + dp[i]) % base;
        }
        return res;
    }
};
